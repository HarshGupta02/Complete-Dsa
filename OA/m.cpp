int max_index = 0;
for (int i = 1; i <= N; i++) {
    max_index += i;
}
int current_index = max_index, step = N;
while (1) {
    while (current_index > 0 && N > 0) {
        current_index -= N;
        if (current_index == B) {
            current_index += N;
        }
        N--;
    }
    if (current_index <= 0) {
        return max_index;
        break;
    }
    else {
        N = step;
        current_index = max_index - 1;
        max_index--;
        if (current_index == B) {
            current_index = max_index - 1;
                max_index--;
        }
    }
}
return -1;