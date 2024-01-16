string isItPossible(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty){
            if (tx < ty) ty %= tx;
            else tx %= ty;
        }
        return (sx == tx && sy <= ty && (ty - sy) % sx == 0 ||
               sy == ty && sx <= tx && (tx - sx) % sy == 0) ? "YES" : "NO";
    }

string isItPossible(int sx, int sy, int tx, int ty) {
    while(tx >= sx && ty >= sy){
        if(tx > ty){
            if(sy == ty) return ((tx - sx) % ty == 0) ? "NO" : "YES";
            tx %= ty;
        }else{
            if(sx == tx) return ((ty - sy) % tx == 0) ? "NO" : "YES";
            ty %= tx;
        }
    }   
    return "NO";
}