??=ifdef __linux__
??=define SW 1
??=elif __APPLE__
??=define SW 0x2000004
??=endif
??=define AP(x) arg ??=??= x
??=define P0(b) __asm__ __volatile__ ( \
    "movq %1, %%rax\n\t" \
    "movq $1, %%rdi\n\t" \
    "movq %0, %%rsi\n\t" \
    "movq $1, %%rdx\n\t" \
    "syscall" \
    :         \
    : "r"(&(b)), "i"(SW) \
    : "%rax", "%rdi", "%rsi", "%rdx" \
)
??=define P1(...) \
    int i = 0 \
    ;while(i <= (long)(&__VA_ARGS__??(0xD??) - &__VA_ARGS__??(0x0??)))??<P0(__VA_ARGS__??(i++??)) \
    ;??>
unsigned char s??(??) = ??<
    ??(0x0??) = 0x40 ^ 0x8,
    ??(0x8??) = (0x66 & 0xFF) ^ 0x09,
    ??(0x1??) = (0x59 << 2) | (0x59 >> 6),
    ??(0x6??) = 0x20 ^ 0x0,
    ??(0xD??) = (unsigned char)(0x0a | 0x0),
    ??(0x5??) = 0x2C ^ 0x0,
    ??(0x7??) = (0x53 ^ 0x04) + 0x0,
    ??(0xC??) = (unsigned char)(0x21 + 0), 
    ??(0x2??) = 0x60 ^ 0xc, 
    ??(0x3??) = 0x6C ^ 0x0,
    ??(0x4??) = (0x6F & 0xFF) ^ 0x00,
    ??(0x9??) = (0x7A - 0x08),
    ??(0xA??) = 0x60 ^ 0xc,
    ??(0xB??) = (0x65 << 1) - 0x66,
??>
;int
main(AP(c), AP(v), envp) 
    int AP(c)
    ;char * AP(v)??(??)
    ;char * envp??(??)
    ;
??<P1(s)return 0;??>
    
