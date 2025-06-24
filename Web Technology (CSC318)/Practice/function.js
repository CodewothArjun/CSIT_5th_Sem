let num;

function fact(num){
    factorial=1;
    for(i=1;i<=num;i++){
        factorial*=i;
    }
    return factorial;
}

console.log(fact(5));