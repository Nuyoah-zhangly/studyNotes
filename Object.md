# 对象的方法 
- javascript 中，对象的键/值对的集合。值可以包含属性和方法,并且可以包含所有其他的javascript的数据类型，例如字符串，数字，布尔值
- javascript的所有对象都来自父Object的构造函数Object 为我们提供了很多内置的方法，并且可以在单个对象中使用。不同于数组的原型对象 例如
- sort() 和reserve() 只能被数组实例使用,对象的方法直接来自Object 构造函数，并使用对象实例作为参数，这种方法成为静态方法。

```javascript
Object.create() //方法用于创建一个新对象,并将其链接到现有的原型对象 我们可以创建一个job 对象实例
const job = {
  position:'cacher',
  type:'hourly',
  isAvalable:true,
  showDatils(){
    const accepting = this.isAvalable ? 'is accepting applicate':'is not currently accepting'
    console.log(`THE ${this.option} option is ${this.type} and ${accepting}`)
  }
}
const barista = Object.create(job)
barista.position = "barista";
barista.showDatils()
//barista 对象 现在有一个position 属性 但是所有其属性和方法都可以通过job 的原型获得，通过Object.create()来实现最小的重复，对于保持DRY十分有效
//DRY 软件开发原则 ,亦在 减少图案的重复主张抽象的，避免冗余

```

```javascript
Object.keys() //创建一个包含对象键的数组
//我们可以创建一个对象，并打印键的数组
const employees = {
  boss:'Micheal',
  secretary:'Pam',
  salas:'Jim',
  accountant:'Oscar'
}
// get the keys of object

const keys =  Object.keys(employees)
console.log(keys) // ["boss", "secretary", "salas", "accountant"]

---
Object.keys() //还可以用于迭代对象的键和值
//Iterate througt the keys
Object.keys(employees).forEach(key =>{
  let value = employees[key];
  console.log(`${key}:${value}`); //boss:Micheal secretary:Pam  salas:Jim accountant:Oscar
})
Object.keys(employees).map(index =>{
  let values = employees[index]
  console.log(`${values}`)   //Micheal Pam Jim  Oscar
}) 
```

- for in 循环和Object.keys() 返回的可枚举属性有个区别：
- for in 循环同时也会遍历原型对象
- Object.keys() 只会返回自有的(实例) 属性

```javascript

const length = Object.keys(employees).length  //可用于检测对象的长度
console.log(length)


```
---
```javascript
Object.values() //创建一个包含对象值的属性
//Initialize an object
let session = {
  id:2,
  time:new Date(),
  device:'moblie',
  browser:'Chreme'
}

// Get all values of the Object
const values = Object.values(session);
console.log(values) // [2, Fri Jun 26 2020 14:50:08 GMT+0800 (中国标准时间), "moblie", "Chreme"]

```
- Object.keys() 和 Object.values() 允许你从对象返回数据
---

```javascript
Object.entries() //创建对象的键/值对的嵌套数组

//Initialize an object
const opearatingSystem = {
  name:'Ubuntu',
  version:18.04,
  licence:'Open Source'
}

//get the object key/object pairs

const entries = Object.entries(opearatingSystem);
console.log(entries)  //

// [
//     ["name", "Ubuntu"]
//     ["version", 18.04]
//     ["license", "Open Source"]
// ]

```
-  一旦我们有了键和值对数组，我们就可以使用该forEach() 方法循环并处理结果

```javascript
entries.forEach(entry =>{
  console.log(entry)  // ["name", "Ubuntu"] ["version", 18.04]  ["licence", "Open Source"]
  const [key,value] = entry
  console.log(`${key}  : ${value}`) // name  : Ubuntu  version  : 18.04  licence  : Open Source
})
```
- Object.entries() 方法仅返回对象实例的自己属性，而不返回可以通过其原型继承的任何属性

---
```javascript
Object.assign() //用于把一个对象的值复制到了另一个对象

//我们可以创建两个对象,使用Object.assign() 方法将他们合并
//Initalize an object 
let name = {
  firstName:'Philip',
  lastName:'Planet Express'
}

//Initalize anthor object

let details = {
  job:'Delivery',
  employer:'Planet Express'
}
//merge the object
const character = Object.assign(name,details);
console.log(character) //{firstName: "Philip", lastName: "Fry", job: "Delivery Boy", employer: "Planet Express"}

//
```

```javascript 
//通过展开语法结合 name 和details 对象，声明 character 对象

//Initalize an object
let name = {
  firstName:'Philip',
  lastName:'Planet Express'
}
//Initalize other object
let details = {
  job:'Delivery',
  employer:'Planet Express'
}
 
const character = {...name,...details} //{firstName: "Philip", lastName: "Fry", job: "Delivery Boy", employer: "Planet Express"}

 ```  

 ---
 ```javascript
 Object.freeze()  //防止修改对象的属性和值，并防止在对象中添加或删除属性。
 //Initalize an object
 const user = {
   userName:'Auure',
   password:'hun2'
 }

 //freeze the object
const newUser = Object.freeze(user)
newUser.password = '******',
newUser.active = true

console.log(newUser) //{userName: "Auure", password: "hun2"}

//重新填写密码去覆盖 password的值一直保持不变，特意为他添加一个新的属性active 但是并没有添加
//Object.isFrozen 用于确定对象是否已冻结 ，并返回布尔值


 ```

---

```javascript

Object.seal()  //阻止将新属性添加到对象，但允许修改现有属性  但这种方法类似于Object.freeze() 

const user = {
    username: 'AzureDiamond',
    password: 'hunter2'
};
// Seal the object
const newUser = Object.seal(user);

newUser.password = '*******';
newUser.active = true;

console.log(newUser); //{username: "AzureDiamond", password: "*******"}

//新的  active 属性未能添加到加密对象 但是password 属性已经更改
//Object.isSeal() 可用确定对象是否已经关闭，并返回布尔值

```

---
```javascript
Object.getPrototypeOf() //用于获取[[Prototype]] 对象的内部隐藏，也可以通过 _proto_ 属性访问。

const employees = ['Ron', 'April', 'Andy', 'Leslie'];
Object.getPrototypeOf(employees) //[constructor: ƒ, concat: ƒ, find: ƒ, findIndex: ƒ, pop: ƒ, …]
 //该原型输出中可以看到 employees 访问数组pop。find 以及其他的数组原型方法，我们可以通过测试 原型来证实Arrary.prototype

console.log(Object.getPrototypeOf(employees) === Array.prototype) //true
//可用于获取有关对象的更多信息或确保它可以访问另一个对象的原型。

//还有一种相关Object.setPrototypeOf()方法将一个原型添加到另一个对象。建议您使用Object.create()， 因为它更快，性能更高。
```



