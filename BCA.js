// [1] Program
function outer() {
  var a = 10;
  let b = 20;
  const c = 30;

    console.log("Outer: ", a);
    console.log("Outer: ", b);
    console.log("Outer: ", c);

  function inner() {
    var d = 100;
    console.log("Inner: ", a);
    console.log("Inner: ", b);
    console.log("Inner: ", c);
  }
  console.log(d);

  inner();
}
outer();

// [2] Program
const res = () => {
  console.log("Hello");
};
res();

// [3] Program
function fact(n){
    if(n===1) return 1;
    return n * fact(n-1);
}
const res2 = fact(5);
console.log(res);

// [4] Program
function sum(a, b){
    return a + b;
}
const res3 = sum(10,20)
console.log(res);
console.log(sum(100,200));

// [5 TO 10] Program
const arr = [10, 50, 30, 80, 100, 15];
console.log("Original Arr: ", arr);
const arr1 = [100, 200, 300];
arr.pop();
arr.shift()
arr.unshift(1000)
arr.push(500)
arr.reverse()
console.log(arr.length);
console.log(arr.indexOf(100));
const arr2 = arr.concat(arr1);
console.log(arr2);
console.log(arr.join());

// [11 TO 15] Program
const str = "test12@gmail.com ";
const str1 = "jhgjhg"
const str2 = str.concat(str1)
const test1 = str.length
const test2 = str.trim()
const test3 = str.indexOf("@")
const test4 = str.charAt("10")
const test5 = str.replace("@", "#")
const test6 = str.includes("@")
const test7 = str.startsWith("T")
const test8 = str.split()
const test9 = str.slice(1,4)
const test10 = str.substring(0, 4) + "****";
const test11 = str.toUpperCase()
const test12 = str.toLowerCase()


console.log(test1);
console.log(test2);
console.log(test3);
console.log(test4);
console.log(test5);
console.log(test6);
console.log(test7);
console.log(test8);
console.log(test9);
console.log(test10);
console.log(test11);
console.log(test12);

// [16 TO 20] Program
const obj  = {id:1, name:"JavaScript", version:20};
const objStr = JSON.stringify(obj);

console.log(Object.keys(obj));
console.log(Object.values(obj));
console.log(JSON.stringify(obj));

console.log(JSON.parse(objStr));

Object.seal(obj)
Object.freeze(obj)
obj.version = 30;
delete obj.name
console.log(obj);

console.log(Object.entries(obj));
console.log(obj.hasOwnProperty("name1"));

console.log("name" in obj);