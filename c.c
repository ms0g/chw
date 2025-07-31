??=ifdef __linux__
??=define S 1
??=elif __APPLE__
??=define S 0x2000004
??=endif
??=define AP(x) arg ??=??= x
??=define X(a, b) (((a) ??! (b)) & ??-((a) & (b)))
??=define P(b) __asm__ __volatile__ ( \
    "movq %1, %%rax\n\t" \
    "movq $1, %%rdi\n\t" \
    "movq %0, %%rsi\n\t" \
    "movq $1, %%rdx\n\t" \
    "syscall" \
    :         \
    : "r"(&(b)), "i"(S) \
    : "%rax", "%rdi", "%rsi", "%rdx" \
)
??=define W(...) \
    long l = (long)(&0xE??(__VA_ARGS__??) - &0x0??(__VA_ARGS__??)); \
    unsigned char* p = (unsigned char*)&0x0??(__VA_ARGS__??); \
    switch(l % 8) ??< \
        case 0: do ??< P(*p++); \
        case 7: P(*p++); \
        case 6: P(*p++); \
        case 5: P(*p++); \
        case 4: P(*p++); \
        case 3: P(*p++); \
        case 2: P(*p++); \
        case 1: P(*p++); \
        ??> while((l -= 8) > 0);??>

struct ??<
unsigned short : 0;
unsigned char (h)??(??);
??> static const h = ??<
    .h = ??<
    ??(0x0??) = X(0x40, 0x8),
    ??(0x8??) = X(0x66 & 0xFF, 0x09),
    ??(0x1??) = (0x59 << 2) ??! (0x59 >> 6),
    ??(0x6??) = 0x20 ^ 0x0,
    ??(0xD??) = (unsigned char)(0x0a ??! 0x0),
    ??(0x5??) = ??-0xD3,
    ??(0x7??) = (0x53 ^ 0x04) + 0x0,
    ??(0xC??) = (unsigned char)(0x21 + 0), 
    ??(0x2??) = X(0x60, 0xc), 
    ??(0x3??) = ~0x93,
    ??(0x4??) = (0x6F & 0xFF) ^ 0x00,
    ??(0x9??) = (0x7A - 0x08),
    ??(0xA??) = X(0x60, 0xc),
    ??(0xB??) = (0x65 << 1) - 0x66 ??>
??>;

int x = 0;
int
main(AP(c), AP(v), envp) 
    int AP(c)
    ;const char const * const AP(v)??(??)
    ;const char const * const envp??(??)
    ;
??<int x = 0xFFFFFFFFFFFFFFFF;W(h.h);??< extern int x; return x; ??>??>
    
