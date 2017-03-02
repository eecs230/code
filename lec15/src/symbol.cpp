#include "symbol.h"

Symbol_table& Symbol_table::instance()
{
    static Symbol_table inst;
    return inst;
}

symbol Symbol_table::intern(const std::string& name)
{
    auto& slot = table_[name];
    auto ptr = slot.lock();

    if (!ptr) {
        ptr = std::make_shared<symbol::repr>(name);
        slot = std::weak_ptr<symbol::repr>(ptr);
    }

    return symbol{ptr};
}

void Symbol_table::clean()
{
    auto limit = table_.end();
    for (auto i = table_.begin(); i != limit; ) {
        if (i->second.expired())
            i = table_.erase(i);
        else
            ++i;
    }
}

symbol intern(const std::string& name)
{
    return Symbol_table::instance().intern(name);
}
