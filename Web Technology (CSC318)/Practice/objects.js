// let person={
//     fname:"Arjun",
//     lname:"Mijar",
//     activity:function(num){
//         return `The total number (${num}+5) is `+ (num+5);
//     },
//     email:"arjun@gmail.com"
// };

// console.log(person.fname)
// console.log(person.activity(3));
// console.log(person["email"]);


// let user={
//     fname:"Ram",
//     phone:"3252",
//     greet:function(){
//         console.log("Hello, "+this.fname);
//     }
// }

// user.greet()


//constructor objects
function person(name,age){
    this.name=name;
    this.age=age;
}

let Ram=new person("Ram",22);
let Shyam=new person("Shyam",30);

console.log(Ram.age)
console.log(Shyam.age);
