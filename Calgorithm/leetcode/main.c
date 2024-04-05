

// main 함수 예시 1

int main() {
    char s[51];
    scanf("%s", s);
    printf("%d\n", shortest_palindrome_length(s));
    return 0;
}


// main 함수 예시 2
int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char s[100001];
        scanf("%s", s);
        int result = analyze_string(s);
        printf("%d\n", result);
    }
    return 0;
}
