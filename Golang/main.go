/*
 * @Author: Shepherd Qirong
 * @Date: 2022-06-26 22:29:41
 * @Github: https://github.com/ShepherdQR
 * @LastEditors: Shepherd Qirong
 * @LastEditTime: 2022-06-26 23:03:21
 * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
 */

package main

//import "fmt"

type Int struct {
	v int
}

/*
1) go 没有 while
2) for 无括号
*/

/*

此时我们需要在GoPath路径下的 cmd 中输入：

go env -w GO111MODULE=on

go env -w GOPROXY=https://goproxy.cn,direct

修改代理到国内的go，然后在 cmd 重新获取即可成功：

go.exe install  -v golang.org/x/tools/gopls

使用结束后需关闭 GO111MODULE

go env -w GO111MODULE=off
-----------------------------------
关于vscode无法安装成功gopls等插件的问题
https://blog.51cto.com/u_15127620/4533825

*/

func main() {
	/*
		for i := Int{v:0}; i.v<10; i.v++{
			println(i.v)
		}
		这里编译器认为for循环是下面三行：
		for i := Int{
			v:0
		};

		i.v<10; i.v++{
			println(i.v)
		}

	*/
	//结构体的构造这里要加括号
	for i := (Int{v: 0}); i.v < 10; i.v++ {
		println(i.v)
	}

	println("Hello, World!")
	//fmt.Println("Hello, World!")
}
