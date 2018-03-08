#include "bit_io.h"
#include <catch.h>
#include <memory>

using bistream_ptr = std::shared_ptr<bistream>;
using bostringstream_ptr = std::shared_ptr<bostringstream>;

using bytes_t = std::vector<uint8_t>;

static bistream_ptr make_bistringstream(std::vector<uint8_t> bytes) {
    return bistream_ptr(new bistringstream(bytes));
}

TEST_CASE("BISTREAM1") {
    auto b = make_bistringstream({0});
    bool bit;

    b->read(bit);
    CHECK_FALSE( bit );
}

TEST_CASE("BISTREAM2") {
    auto b = make_bistringstream({255});
    bool bit;

    b->read(bit);
    CHECK( bit );
}

TEST_CASE("BISTREAM3") {
    auto b = make_bistringstream({128});
    bool bit;

    b->read(bit);
    CHECK( bit );
}

TEST_CASE("BISTREAM4") {
    auto b = make_bistringstream({1 << 6 | 1 << 5});
    bool bit;

    b->read(bit);
    CHECK_FALSE( bit );
    b->read(bit);
    CHECK( bit );
    b->read(bit);
    CHECK( bit );
}


TEST_CASE("BISTREAM5") {
    auto b = make_bistringstream({255, 1 << 6 | 1 << 5});
    bool bit;

    for (int i = 0; i < 8; i++) {
        b->read(bit);
    }

    b->read(bit);
    CHECK_FALSE( bit );
    b->read(bit);
    CHECK( bit );
    b->read(bit);
    CHECK( bit );
}


TEST_CASE("BISTREAM6") {
    auto b = make_bistringstream({255, 255});
    bool bit;

    for (int i = 0; i < 16; i++) {
        b->read(bit);
        CHECK( bit );
    }
    CHECK( b->eof() );
}


TEST_CASE("BOSTREAM1") {
    bostringstream_ptr b(new bostringstream);
    bostream& br = *b;
    CHECK( 0 == b->bits_written() );
    br.write(false);
    CHECK( 1 == b->bits_written() );
    CHECK( 0 == b->data()[0] );
}

TEST_CASE("BOSTREAM2") {
    bostringstream_ptr b(new bostringstream);
    bostream& br = *b;
    br.write(true);
    CHECK( 128 == b->data()[0] );
}

