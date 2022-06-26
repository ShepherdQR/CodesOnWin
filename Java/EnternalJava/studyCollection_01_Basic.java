/*$$
 $ @Author: Shepherd Qirong
 $ @Date: 2021-09-13 21:35:52
 $ @Github: https://github.com/ShepherdQR
 $ @LastEditors: Shepherd Qirong
 $ @LastEditTime: 2022-06-26 21:37:55
 $ @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
 $*/

// This document is built on 20210913




public class studyCollection_01_Basic {

	public static void test() {
		T0002Study20220626.test();
		//T0001Study20210913.func20210913();
	}

	// var can be variable name
	static class T0002Study20220626 {

		static class A{
			int var = 20220626;
			void var(int n){
				System.out.println(n);
			}
		}
		static A var(){return new A();}
	
		static void test(){
			var var = var();
			var.var(var.var);
		}
	}

	// basic test
	static class T0001Study20210913 {
		public static void func20210913() {
			System.out.println("HelloWorld 20210913..");
		}
	}
}

