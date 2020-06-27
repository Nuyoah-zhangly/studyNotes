# 字符串的方法

## 常用的字符串方法以及使用方式

```txt
字符串有三个特质constructor ,length , prototype
```

- 1 charAt(x) 返回字符串中x位置的字符 下标从0 开始
```javascript 
let myString = 'this a string'
let charAtString = myString.charAt(7)
console.log(charAtString)  //s
```
- 2 charCodeAt(x)  返回字符串中位置所处字符的unicode值
```javascript
//charCodeAt(position)

let message = 'hello'
let charCodeAtMs = message.charCodeAt(1)
console.log(charCodeAtMs)  //101

```
- 3 concat(v1,v2..) 用于连接两个或者多个字符串，此方法不改变现有的字符串返回拼接后的新的字符串。
```javascript
let message = 'Sam'
let final = message.concat(' is a hopeless romantic')
console.log(final)  //Sam is a hopeless romantic

```
- 4 fromCharCode(c1,c2) 转换一组unicode值转换为字符

```javascript 
console.log(String.fromCharCode(99,97,98)) //cab
```
- 5 indexOf(substr,[start]) 方法搜索并(如果找到)返回字符串或者子字符串的索引，如果没有找到，则返回-1 ,start 是一个可选参数，指定字符串中开始是索引的位置，默认为0.
```javascript
//indexOf(char/subtring)
let sentence = "Hi,my name is Sam！"
if(sentence.indexOf('Sam') != -1){
  console.log('Sam is in here')
}

```
- 6 lastIndexOf()  方法返回指定文本在字符串中最后一次 出现的索引, 如果没有找到 ，则返回-1 .start是个可选参数，指定字符串中开始搜索的位置，默认为 string.length-1

```javascript

//lastIndexOf(substr,[start])

let myString = 'javascript rox'

console.log(myString.lastIndexOf('r')) //11

```
- 7 match(regexp) 根据正则表达式在字符串中搜索匹配项，如果没有匹配项，则返回一个信息组或者null 

//select integers only

```javascript
let inRegexp = /[0-9 -() +] +$/;
let myNumber = '999'
let myInt =  myNumber.match(inRegexp)
console.log(myInt); //null

```
- 8 replace(regexp/substr,replacetext) 方法用于在字符串中的一些字符替换另一些字符，或者替换一个与正则表达式匹配的子串
```javascript

// replace(substr,replacetext)
let mySring = '999 javascript Coders'

let replaceString = mySring.replace(/javascript/i, 'css')
console.log(replaceString) //999 css Coders

// replace(regexp,replacetext)


let regReplaceSrting = mySring.replace(new RegExp('999',"gi"),'The')
console.log(regReplaceSrting) //The javascript Coders

```
- 9 search(regexp) 方法用于检测字符串中指定 的子字符串 ，或者检测 与正则表达式相匹配的子字符串，如果找到，返回与regexp相匹配的子串的起始位置，否则返回-1

```javascript
// search(regexp)

let intRegex = /[0-9 -()+]+$/;
let myNumber = '999'
let isInt = myNumber.search(intRegex)
console.log(isInt) // 0

```
---

- 10 slice(start,[end]) 方法可以提取字符中某个部分，返回一个新的字符串，包括字符串从start 开始（start）到end结束（不包括end）为止的所有字符
```javascript
let text = "excellent"
let sliceText = text.slice(0,2)
let sliceText1 = text.slice(2,5)

console.log(sliceText)  //ex
console.log(sliceText1) //cel


```
- 11 splice(delimiter,[limit]) // 方法用于把一个字符串分割成字符串数组，返回一个字符串数组返回的数组中的字符串不包括delimiter(分隔符)自身。可选limit是一个整数，允许指定要返回的最大的数组元素个数。

- 12 substr() 方法可以在字符串中抽取从start 下标开始的指定数目的字符，返回一个新的字符串，包含从start(包括 start所指定的字符) 处开始的length 个字符，如果没有指定length，那么返回的字符串包含从start 到该字符串的结尾处

```javascript
substr(from,to)

let text = 'excellent'
let substrText = text.substr(0,4) //4截取的长度
let substrText1 = text.substr(2,4)
console.log(substrText) //exce 
console.log(substrText1)  //cell
```

- 13 substring(from,[to]) 方法用于提取字符串中介于两个指定下标之间的字符 ，方法返回的子串 包括start 处的字符，但不包括stop处的字符，to可选，如果省略该参数，那麽返回的子串一直到字符串的结尾。
```javascript
let myString = 'javascript rox'
myString = myString.substring(0,10)
console.log(myString) //javascript

```
---
```text 

slice substr substring 的区别
当传入的参数都为正数时,substring 和substr 没有什么区别 ，当参数为负数时三个函数不尽相同

slice() 将传入的负参数与字符长度相加
substring() 把所有的负数置为0
substr() 将负的第一个参数与字符串相加，负的第二个参数置为0、




```


```javascript
 //参数为正数
let str = "hello world"
console.log(str.substr(3)) //lo world
console.log(str.substring(3)) //lo world
console.log(str.slice(3)) //lo world

console.log(str.substr(3,7)) //lo worl
console.log(str.substring(3,7)) //lo w
console.log(str.slice(3,7)) //lo w

//参数为负数

let str = "hello world"
console.log(str.substr(-3)) //rld
console.log(str.substring(-3)) //hello world
console.log(str.slice(-3)) //rld

console.log(str.substr(3,-4)) //空字符串
console.log(str.substring(3,-4)) //hel
console.log(str.slice(3,-4)) //lo w

```

```text
以上实例的计算过程如下
slice(-3) => slice(8)
substring(-3) => substring(0)
substr(-3) => substr(8)
slice(3, -4) => slice(3, 7)
substring(3, -4) => substring(3, 0) =>substring(0, 3)
substr(3, -4) => substr(3, 0)
```
---



- 14 toUpperCase() 方法用于把字符串转换为大写
```javascript
let myString = "excellent"
myString = myString.toUpperCase()
console.log(myString) //EXCELLENT
```
- 15 toLowerCase() 方法用于把字符串转换为小写

```javascript
let myString = "EXCELLENT"
myString = myString.toLowerCase()
console.log(myString)  // excellent

```

- 16 includes() 方法用于检查字符串 是否包含指定的字符串或字符

```javascript
let myString = "hello,welcome to home "
let n = myString.includes('hello')
console.log(n) // true
 
```
- 17 startsWith() 函数检查字符串是否以指定的字符串或者字符开始

```javascript

let myStr = 'List of javascript functions'

var n = myStr.startsWith("a")

console.log(n) //false

```

- 18 endsWith() 函数检查字符串是否以指定的字符串或者字符结束

```javascript

let myStr = 'List of javascript functions'

var n = myStr.endsWith("a")
console.log(n) //true

```

- 19 repeat()构造返回一个新的字符串，该字符串 包含 被连接在一起的指定数量的字符副本。

```javascript
let str = "hello,welcome to home"
 
 let repeatStr = str.repeat(3)
 console.log(repeatStr) //hello,welcome to homehello,welcome to homehello,welcome to home
 
```

- 20 valueOf() 方法返回一个String 对象的原始值(primitive value) ,该值等同于String.prototype.toString()
```javascript
let myStr = "hello world"
let res = myStr.valueOf()
console.log(res) //hello world

```
```text
valueOf()和 toString() 的区别

不同之处在于 toString() 返回 的是字符串,而valueOf() 返回的是原对象

```


- 21  trim() 方法会从一个字符串中的两端删除空白字符，在这个上下文中的空白字符是所有的空白字符串（space，tab no-break，spaced等）以及所有行终止字符

```javascript
let str = "  hello  "
let trimStr = str.trim(str)
console.log(trimStr) //hello

```