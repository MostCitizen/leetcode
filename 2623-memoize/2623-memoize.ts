type Fn = (...params: number[]) => number

function memoize(fn: Fn): Fn {
    const cashe = new Map<string, number>();
    var count:number = 0;
    return function(...args) {
        if(args.length == 0){
            return count;
        }
        count++;
        const key = JSON.stringify(args);
        if(cashe.has(key)){
            return cashe.get(key);
        }
        const res = fn(...args);
        cashe.set(key, res);
        return res;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */