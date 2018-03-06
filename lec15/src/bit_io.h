#pragma once

/*
 * bit_io.h: classes for reading and writing files one bit (or more)
 * at a time.
 *
 * The main idea is that we create a bit input or output stream as a
 * layer over a file that we open for reading or writing. The library
 * maintains a buffer of bits so that the client can view the file as a
 * simple sequence of bits rather than bytes.
 */

#include <cstdint>
#include <istream>
#include <ostream>
#include <fstream>
#include <vector>
#include <initializer_list>

/*
 * INPUT
 */

// Bit input stream, for reading individual bits from a file or a std::vector<uint8_t>
// This is an abstract base class for the concrete derived classes
// `bistream_adapter`, `bifstream`, and `bistreamstream` defined below. It
// defines the common interface for those classes.
class bistream {
public:
    // Reads a bit from this bit input stream into the given bool
    // reference.
    bistream &read(bool &result);

    // Determines whether we've reached the end of the input file.
    //
    // Returns: `true` if we’ve attempted to read past the end of
    // the file, and `false` otherwise.
    virtual bool eof() const;

    // Determines the status of the bit input stream.
    //
    // Returns: `false` if there are no bits to read and a read
    // error has occurred, and `true` otherwise.
    virtual bool good() const;

    // The bit input stream boolean coercion operator, inserted, for
    // example, when a `bifstream` is used as a condition for an
    // `if`. Alias for `good()`.
    operator bool() const;

protected:
    // Classes that derive from this one should override `get_next_byte`,
    // which attempts to read one byte from the source, returning true on
    // success or false on failure.
    virtual bool get_next_byte(uint8_t&) = 0;

private:
    uint8_t nbits_ = 0;
    uint8_t bitbuf_ = 0;
};

// Adapts any `std::istream&` for use as a bit input stream.
class bistream_adapter : public bistream {
public:
    // Constructs a bit input stream on top of an input stream. Does not
    // take ownership of the `std::istream`. However, using the `istream`
    // while also using the adapter, or adapting the same `istream`
    // twice, will give strange results.
    explicit bistream_adapter(std::istream&);

    bool eof() const override;

    bool good() const override;

    bistream_adapter(const bistream_adapter &) = delete;

private:
    std::istream& stream_;

    virtual bool get_next_byte(uint8_t&) override;
};

class bifstream : public bistream_adapter {
public:
    // Constructs a bit input stream to read from the given file.
    explicit bifstream(const char *filespec);

    bifstream(const bifstream &) = delete;

private:
    std::ifstream base_;
};

class bistringstream : public bistream {
public:
    // Constructs a bit input stream from the given vector of bytes.
    explicit bistringstream(std::vector<uint8_t>);

    // Creates a bit input stream containing exactly the given bits.
    explicit bistringstream(std::initializer_list<bool>);

    bool eof() const override;

    bool good() const override;

    bistringstream(const bistringstream &) = delete;

private:
    size_t bytes_index_;
    std::vector<uint8_t> bytes_;

    virtual bool get_next_byte(uint8_t&) override;

};

// The bit input stream extraction operator; alias for `read(bool&)`.
bistream &operator>>(bistream &bif, bool &b);

/*
 * OUTPUT
 */

// A bit output stream, for writing individual bits to a file.
class bostream {
public:
    // Writes a bit to this bit output stream.
    virtual bostream &write(bool b) = 0;

    // Determines the status of the bit output stream.
    virtual bool good() const = 0;

    // The bit output stream boolean coercion operator, inserted, for
    // example, when a `bofstream` is used as a condition for an
    // `if`. Alias for `good()`.
    operator bool() const;

};

// Adapts any `std::ostream&` for use as a bit output stream.
class bostream_adapter : public bostream {
public:
    // Constructs a bit output stream to write to the given output stream.
    explicit bostream_adapter(std::ostream&);

    virtual bostream_adapter &write(bool b) override;

    virtual bool good() const override;

    ~bostream_adapter();

    bostream_adapter(const bostream_adapter &) = delete;

private:
    uint8_t bitbuf_;
    size_t nbits_;
    std::ostream& stream_;

    void write_out_();
};

class bofstream : public bostream_adapter {
public:
    // Constructs a bit output stream to write to the given file.
    explicit bofstream(const char *filespec);

    bofstream(const bofstream &) = delete;

private:
    std::ofstream base_;
};

class bostringstream : public bostream {
public:
    const std::vector<uint8_t>& data() const;

    virtual bostringstream &write(bool b) override;

    virtual bool good() const override;

    size_t bits_written() const;

private:
    size_t bits_written_ = 0;
    std::vector<uint8_t> data_;

};

// The bit output stream insertion operator; alias for
// `write(bool)`.
bofstream &operator<<(bofstream &bof, bool b);
