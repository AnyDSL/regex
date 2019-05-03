#include <string>
#include <iostream>

#define RUNTIME_ENABLE_JIT
#include <anydsl_runtime.h>

// Generated from regex.impala
#include "regex.inc"

std::string escape(const std::string& str) {
    std::string res;
    for (auto c : str) {
        switch (c) {
            case '\n': res += "\\n"; break;
            case '\t': res += "\\t"; break;
            default:   res += c;     break;
        }
    }
    return res;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: regex <regular expression> <string>" << std::endl;
        return 1;
    }
    
    std::string suffix;
    suffix += "extern fn entry(str: &[u8]) -> bool {\n";
    suffix += "    let (ok, _) = parse(\"" + escape(argv[1]) + "\")(str, 0);\n";
    suffix += "    ok\n";
    suffix += "}\n";
    std::string file_str = std::string((char*)regex_impala) + suffix;

    auto key = anydsl_compile(file_str.c_str(), file_str.size(), 3);
    typedef bool (*MatchFn)(const char*);
    auto match = reinterpret_cast<MatchFn>(anydsl_lookup_function(key, "entry"));
    if (match(argv[2])) {
        std::cout << "MATCH!" << std::endl;
    } else {
        std::cout << "NO MATCH" << std::endl;
    }
    return 0;
}
