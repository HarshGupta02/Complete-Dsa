int n = sentence.length(), i = 0, currlen = 0, maxlen = 0, st = -1;
while (i < n) {
    if (sentence[i] == ' ') {
        if (!(currlen & 1)) {
            if (maxlen < currlen) {
                maxlen = currlen;
                st = i - currlen;
            }
        }
        currlen = 0;
    }
    else currlen++;
    i++;
}
if (!(currlen & 1)) {
    if (maxlen < currlen) {
        maxlen = currlen;
        st = i - currlen;
    }
}
return st == -1 ? "00" : sentence.subtr(st, maxlen);