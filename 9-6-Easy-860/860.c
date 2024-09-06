bool lemonadeChange(int* bills, int billsSize) {
  int fn = 0, tenn = 0;
  for(int i = 0; i < billsSize; i++){
    if(bills[i] == 5)
        fn++;
    else if(bills[i] == 10){
        if(fn == 0)
            return false;
        fn--;
        tenn++;
    }
    else if(bills[i] == 20){
        if(fn == 0 || (tenn == 0 && fn < 3))
            return false;
        if(tenn > 0){
            tenn--;
            fn--;
        }
        else if(tenn == 0)
            fn = fn - 3;
    }
  }
  return true;              
}
