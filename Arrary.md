# 数组的方法
- 1 arr.push() 从后边添加元素 ,返回值为添加后的数组长度
```javascript

let arr = ['🍎','🍇','🍌']
 
let addArr = arr.push('😂')

console.log(arr)  //["🍎", "🍇", "🍌", "😂"] 
console.log(addArr) //4

```
- 2 arr.pop() 从后边删除元素,只能是一个,返回值是删除的元素

``` javascript

let arr = ['🍎','🍇','🍌']
let popArr = arr.pop()

console.log(arr)  // ["🍎", "🍇"]
console.log(popArr)  // 🍌

```

- 3 arr.shift() 从前边删除元素,只能删除一个 返回值是删除的元素

```javascript

let arr = ['🍎','🍇','🍌']
let shiftArr = arr.shift()
console.log(arr)  //["🍇", "🍌"]
console.log(shiftArr)  //🍎

```

- 4 arr.unshift() 从前边添加元素,返回值是添加完后的数组长度

```javascript

let arr = ['🍎','🍇','🍌','😂']
let unshiftArr = arr.unshift(1)
console.log(unshiftArr) //5
console.log(arr) //[1, "🍎", "🍇", "🍌", "😂"]

```

- 5 arr.concat() 连接两个数组,返回值为连接后的新数组

```javascript

let arr = ['🍎','🍇','🍌','😂']
let arr1 = ['1','2','3']

let concatArr = arr.concat(arr1)
console.log(concatArr) //["🍎", "🍇", "🍌", "😂", "1", "2", "3"]

```

- 6 arr.split()将字符串转换为数组

```javascript

let string = '123456'
let stringToArray = string.split('')
console.log(stringToArray) //["1", "2", "3", "4", "5", "6"]

```

-7 arr.sort() 将数组进行排序,返回值是排好的数组，默认是按照最左边的数字进行排序,不是按照数字大小进行排序(默认排序是根据unicode进行排序)
```javascript

let arr = [5,7,8,0,10]
let arrSort = arr.sort()
console.log(arrSort) //[0, 10, 5, 7, 8]

let arrSort1 = arr.sort((a,b) => a-b)
console.log(arrSort1) // [0, 5, 7, 8, 10]

let arrSort2 = arr.sort((a,b) => b-a)
console.log(arrSort2)

```

- 8 arr.reverse() 将数组进行反转，返回值是反转后的数组

```javascript

let arr = [5,7,8,0,10]
let reverseArr = arr.reverse()
console.log(reverseArr)  //[10, 0, 8, 7, 5]
consoler.log(arr)

```

- 9 arr.slice(start,end) 切去索引值start 到索引值end 结束 不包含end的值 返回的值是切割出来的数组

```javascript

let arr = [1,2,3,4,5]
let sliceArr = arr.slice(1)
let sliceArr1 = arr.splice(0,3)
console.log(sliceArr) // [2, 3, 4, 5]
console.log(sliceArr1)

```

---
- 10 arr.forEach() 遍历数组 ,无return 即使有也不会返回任何值，会影响从前的值


```javascript
 let arr = [1,2,3,4]

 arr.forEach((value,index,array) =>{
   console.log(`value:${value}`,`index:${index}`,`array:${array}`)
 })

 //value:1 index:0 array:1,2,3,4
 //value:2 index:1 array:1,2,3,4
 //value:3 index:2 array:1,2,3,4
 //value:4 index:3 array:1,2,3,4

 arr.forEach((item,index,arr) =>{
   arr[index] = item * 2
   return arr
 })
 console.log(arr)  // [2,4,6,8]
 
```

- 11 arr.map() 映射数组(遍历数组)，有return 返回一个新的数组

```javascript
let arr = [1,2,3,4]

let res = arr.map((item,index,arr) =>{
  item = item * 3
  return item
})
console.log(res) //[3, 6, 9, 12]
console.log(arr) //[1,2,3,4]

```
```txt
1.arr.forEach()和for 循环一样,是代替for
  arr.map()是修改数组其中的数据,并返回新的数据
2.arr.forEach() 没有return arr.map() 有return

```
- 13 arr.filter() 过滤数组，返回一个新的满足要求的数组

```javascript

let arr = [0,1,2,3,4]
let arr1 = arr.filter((value,index) => index < 3)
console.log(arr1) //[0, 1, 2]

```

- 14 arr.every() 依据判断条件，数组的元素是否全满足，若满足则返回true

```javascript
let arr = [1,2,3,4]
let arr1 = arr.every((value,index)=> value < 3 )
let arr2 = arr.every((value,index) => value  <5)
console.log(arr1) //false
console.log(arr2) //true
     
```
- 15 arr.some() 依据条件判断 ,数组元素是否有一个满足，若有一个满足则返回 true

```javascript
let arr = [1,2,3,4]
let arr1 = arr.some((value,index)=> value < 3 )
let arr2 = arr.some((value,index) => value  <5)
console.log(arr1) //true
console.log(arr2) //true
```
- arr.reduce() 迭代数组的所有项，累加器，数组中的每一个值(从左到右)合并,最终计算为一个值

```javascript
let arr = [0,1,2,3,4]
let arr1 = arr.reduce((preValue,curValue) => preValue + curValue)
console.log(arr1) //10

let arr2 = arr.reduce((preValue,curValue) => preValue + curValue,5)
console.log(arr2) //15
```
执行|preValue|curValue|index|arrary|index
--|:--:|:--:|:--:|:--:|--:
第一次回调|0|1|1|[0,1,2,3,4]|1
第二次回调|1|2|2|[0,1,2,3,4]|3
第三次回调|3|3|3|[0,1,2,3,4]|6
第四次回调|6|4|4|[0,1,2,3,4]|10

执行|preValue|curValue|index|arrary|index
--|:--:|:--:|:--:|:--:|--:
第一次回调|5|0|0|[0,1,2,3,4]|5
第二次回调|5|1|1|[0,1,2,3,4]|6
第三次回调|6|2|2|[0,1,2,3,4]|8
第四次回调|8|3|3|[0,1,2,3,4]|11
第五次回调|11|4|4|[0,1,2,3,4]|15

---
reduce的高级用法







































