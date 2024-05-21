function Person(name) {
    this.name = name;
}

Person.prototype.sayHello = function () {
    return `Hello, my name is ${this.name}!`;
}

let alice = new Person("Alice");
let aliceName = alice.sayHello();
console.log(aliceName);