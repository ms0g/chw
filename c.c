??=ifdef __linux__
??=define S 1
??=elif __APPLE__
??=define S 0x2000004
??=endif
??=define AP(x) arg ??=??= x
??=define C(x, y) (((x) ??! (y)) & ??-((x) & (y)))
??=define P0(b) __asm__ __volatile__ ( \
    "movq %1, %%rax\n\t" \
    "movq $1, %%rdi\n\t" \
    "movq %0, %%rsi\n\t" \
    "movq $1, %%rdx\n\t" \
    "syscall" \
    :         \
    : "r"(&(b)), "i"(S) \
    : "%rax", "%rdi", "%rsi", "%rdx" \
)
??=define P1(...) \
    long l = (long)(&__VA_ARGS__??(0xE??) - &__VA_ARGS__??(0x0??)) \
    ;unsigned char* p = (unsigned char*)&__VA_ARGS__??(0x0??) \
    ;switch(l % 8) ??< \
    case 0: do ??< P0(*p++) \
    ;case 7: P0(*p++) \
    ;case 6: P0(*p++) \
    ;case 5: P0(*p++) \
    ;case 4: P0(*p++) \
    ;case 3: P0(*p++) \
    ;case 2: P0(*p++) \
    ;case 1: P0(*p++) \
            ;??> while((l -= 8) > 0);??>
            
struct ??<
unsigned short : 0;
unsigned char h??(??);
??> static const h = ??<
    .h = ??<
    ??(0x0??) = C(0x40, 0x8),
    ??(0x8??) = C(0x66 & 0xFF, 0x09),
    ??(0x1??) = (0x59 << 2) ??! (0x59 >> 6),
    ??(0x6??) = 0x20 ^ 0x0,
    ??(0xD??) = (unsigned char)(0x0a ??! 0x0),
    ??(0x5??) = 0x2C ^ 0x0,
    ??(0x7??) = (0x53 ^ 0x04) + 0x0,
    ??(0xC??) = (unsigned char)(0x21 + 0), 
    ??(0x2??) = C(0x60, 0xc), 
    ??(0x3??) = 0x6C ^ 0x0,
    ??(0x4??) = (0x6F & 0xFF) ^ 0x00,
    ??(0x9??) = (0x7A - 0x08),
    ??(0xA??) = C(0x60, 0xc),
    ??(0xB??) = (0x65 << 1) - 0x66 ??>
??>

;int
main(AP(c), AP(v), envp) 
    int AP(c)
    ;const char const * const AP(v)??(??)
    ;const char const * const envp??(??)
    ;
??<P1(h.h);return 0;??>
    
