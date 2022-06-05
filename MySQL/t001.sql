
/*
输入以下运行
\. E:\Notes\Notes_Latex\MySQL_study\Codes\t001.sql
*/





-- t001 basic commond
/*
    select user();
    select current_date();
    select current_time();
    select current_timestamp();

    show databases; -- 查看数据库
    create database t001; -- 注意双减号注释，前后都需要空格
    show databases;
    select database(); -- a查看当前选定的库
    use t001; -- b选定当前库
    select database();
    drop database t001; -- c删除库
*/


-- TOO2 create tables
/*
FORIGN KEY 全局不能有重复的名字
*/

/*
    show databases;
    select database();
    use t001;
    show tables;
    drop table if exists Choose_table_02;
    drop table if exists Choose_table_01;
    drop table if exists Classes_table_01;
    drop table if exists Students_table_01;
    show tables;

    CREATE TABLE Students_table_01 (
        id_student int(11) PRIMARY KEY,
        name varchar(22) NOT NULL,
        sex char(2),
        birthday year,
        class varchar(10)
    );
    DESC Students_table_01;

    CREATE TABLE Classes_table_01 (
        id_class int(11) PRIMARY KEY,
        cname varchar(50) NOT NULL,
        points INT(12),
        teacher VARCHAR(10)
    );
    DESC Classes_table_01;

    CREATE TABLE Choose_table_01 (
        id_student int(11),
        id_class int(12),
        score int(11),
        PRIMARY KEY (id_student, id_class),
        CONSTRAINT FK_ID_STUDENT FOREIGN KEY (id_student) REFERENCES Students_table_01(id_student),
        CONSTRAINT FK_ID_CLASS FOREIGN KEY (id_class) REFERENCES Classes_table_01(id_class)
        -- PRIMARY KEY (id_student, id_class)
    );
    DESC Choose_table_01;

    CREATE TABLE Choose_table_02 Like Choose_table_01;
    -- 不复制外键
    ALTER TABLE choose_table_02 
    ADD CONSTRAINT FK_ID_STUDENT_2 FOREIGN KEY (id_student) REFERENCES Students_table_01(id_student);
    -- DROP FOREIGN KEY fk_id_student;
    show create table choose_table_02;
*/



-- TOO3 create tables
/*
 
*/
/*
    SHOW DATABASES;
    DROP DATABASE IF EXISTS t003_factory;
    SHOW DATABASES;
    CREATE DATABASE t003_factory;
    USE t003_factory;
    CREATE TABLE product (
        id varchar(50) PRIMARY KEY,
        name varchar(50),
        price double,
        num int,
        store_id varchar(50)
    );

    CREATE TABLE store (
        id varchar(50) PRIMARY KEY,
        name varchar(50)
    );

    ALTER TABLE product
    ADD CONSTRAINT FK_STORE_ID FOREIGN KEY (store_id) REFERENCES store (id);
    SHOW CREATE TABLE product;
    SHOW CREATE TABLE store;

    -- insert records
    SHOW TABLES;
    INSERT INTO store
    (id, name)
    VALUES
    ("s01", '1仓库');
    SELECT * FROM store;
    INSERT INTO store(id, name) VALUES
    ('s02','2仓库'),('s03','3仓库');
    SELECT * FROM store;

    show variables like '%character%';
*/


-- TOO4 query tables
/*

*/
SHOW DATABASES;
DROP DATABASE IF EXISTS t004_clint;
CREATE DATABASE t004_clint;
USE t004_clint;

CREATE TABLE department(
    deptid int PRIMARY KEY,
    dname varchar(50)
);

CREATE TABLE employee(
    empid int PRIMARY KEY,
    ename varchar(50) NOT NULL,
    sex char(1) DEFAULT 'M',
    job varchar(50),
    hiredate date,
    age int,
    dept_deptid int,
    CONSTRAINT FK_DEPT_DEPTID
    FOREIGN KEY(dept_deptid) REFERENCES department(deptid)
);

INSERT INTO department(deptid, dname) VALUES
(10,'tech'), (20,'depart'), (30, 'renhsi'), (40, 'fina');

INSERT INTO employee VALUES
(1,'zhang san','m','it','1990-02-20',25,10),
(2,'li si','f','it','1991-11-12',23,10),
(3,'wang wu','m','yewu','1989-12-12',32,20),
(4,'zhao liu','f','yewu','1992-12-10',19,20),
(5,'sun qi','m','kuaiji','1975-03-15',38,40);

select * from department;


-- t005 select  5.1 basic
select * from employee;
SELECT ename, job FROM employee;
SELECT ename AS 姓名, job AS 职位 FROM employee;
select ename as Name, age*10 as Reward from employee;
select distinct job from employee;
select * from employee where age>=25 and age <=20;
select * from employee where age between 20 and 25;
select * from employee where age not between 20 and 25;
select * from employee where job='it' or job='yewu';
select * from employee where job in('it', 'yewu');

select * from employee where job = 'it' or job = 'yewu' and age >= 25;
select * from employee where job in('it', 'yewu') and age >= 25;
select * from employee where (job = 'it' or job = 'yewu') and age >= 25;
select * from employee where ename like 'zhang%';
select * from employee where ename like '%an%';
select * from employee order by age desc;
select * from employee order by sex asc, age desc;
select avg(age) as 平均年龄, sum(age) as 年龄和, max(age) as 最大年龄, min(age) as 最小年龄 from employee;
select count(empid) as 人员总数, count(ename) as 人员总数, count(distinct job) as 职位总数, count(*) as 表的记录条数 from employee;

/*
查询所有职员；
查询所有职员姓名、职位，结果带表头；
查询所有姓名、奖金（年龄*10）
显示所有的职位(无重)
查询所有年龄大于等于25岁和小于等于20岁的职员信息
工作为it和业务的。
工作为it和业务的且年龄大于等于25的。
姓张的，模糊查询(%是任意字符， _是任意单个字符)
年龄降序排列，升asc，降desc
先按性别升序，再按年龄降序
平均年龄avg，年龄最大值和最小值，max， min，年龄之和sum
所有职员人数（计数用count).职位个数（去重）
*/

-- t005 select  5.2 basic
select sex as 性别, avg(age) as 平均年龄 from employee group by sex;
-- 按年龄分组，总计每组平均年龄
select job as 职位, count(distinct job) from employee group by job;
select job as 职位, count(job) from employee group by job;

select job as 职位, count(job) from employee group by job having count(job)>1;
select job as 职位, count(job) from employee group by job having count(ename)>1;
-- group by 是分组依据， having 是分组的条件

select * from employee limit 0,3;
select * from employee limit 2,4;-- 从行号2也就是第三行开始读4行
select * from employee limit 3;
-- 检索时 limit 偏移量，记录数。
-- 偏移量是0可以省略。偏移量是0表示从行号0开始，也就是表的第一行。
select * from employee order by age desc limit 3;

select * from employee;
select * from department;

-- t005 select  5.3 basic 跨表查询
/* 
显示职员姓名、职位、部门名称
统计每个部门人数
*/
select ename, job, dname from employee, department
where employee.dept_deptid = department.deptid;
select employee.ename as name, job as job, department.dname as partment
from employee inner join department
where employee.dept_deptid = department.deptid;
select distinct dname as 部门名称, count(ename) as 人数
from employee, department
where employee.dept_deptid = department.deptid;
select  dname as 部门名称, count(ename) as 人数
from employee, department
where employee.dept_deptid = department.deptid;
select  dname as 部门名称, count(ename) as 人数
from employee, department
where employee.dept_deptid = department.deptid
group by dname;


-- t006 三个表查询
drop database if exists t006_grades;
create database t006_grades;
use t006_grades;
select database();

create table students(
    student_id varchar(50) primary key,
    student_name varchar(50),
    student_sex char(1),
    student_birthday date
);
create table course(
    course_id varchar(50) primary key,
    course_name varchar(50)
);
create table selection(
    s_student_id varchar(50),
    s_course_id varchar(50),
    grade int,
    constraint fk_student_id
    foreign key (s_student_id) references 
    students(student_id),
    constraint fk_course_id
    foreign key (s_course_id) references
    course(course_id)
);

insert into students(student_id, student_name, student_sex, student_birthday) values
('s0002', 'LI Si', 'F', '2016-10-02'),
('s0004', 'ZHAO Liu', 'F', '1991-05-01');

insert into course(course_id, course_name) values
('c01','Chinese'),('c02','Math'),('c03','English');

insert into selection values
('s0004','c03', 67),
('s0004','c01', 78),
('s0002','c02',90),
('s0002','c01',89);

-- 根据SQL92规范，多表连接查询
-- 查询选修 英语的 学号和姓名
select student_id as 学号, student_name as 姓名
from students, course, selection
where students.student_id = selection.s_student_id
and course.course_id = selection.s_course_id
and course.course_name = 'English';


-- 根据SQL92规范，多表连接查询
-- 内联，from 字表 inner join 主表
select ename, job, dname from employee, department
where employee.dept_deptid = department.deptid;
select employee.ename as name, job as job, department.dname as partment
from employee inner join department
where employee.dept_deptid = department.deptid;
select employee.ename as name, job as job, department.dname as partment
from employee inner join department
on employee.dept_deptid = department.deptid;

-- 外连，不满足条件的数据也出现在查询结果中
-- left join, right join, full join
select * from employee;
update employee set dept_deptid = null where empid = 5;
select * from employee;

    -- 左外
select employee.ename as name, job as job, department.dname as partment
from employee left join department
on employee.dept_deptid = department.deptid;

    -- 右外
select employee.ename as name, job as job, department.dname as partment
from employee right join department
on employee.dept_deptid = department.deptid;

-- 查询选修 英语的 学号和姓名
select students.student_id, students.student_name from students
inner join selection on students.student_id = selection.s_student_id
inner join 


-- t007 
-- union 去重后合并，union all 不去重
use t006_grades;
show tables;
create table students_copy like students;
insert into students_copy select * from students;
select * from students union all 
select * from students_copy;
select * from students union  
select * from students_copy;  

select student_id from students union 
select student_id from students_copy;
select student_id from students union all
select student_id from students_copy;
select student_id from students union all
select student_sex from students_copy;

-- select 建表与插入记录
create table students_copy2  as select * from students;
select * from students_copy2;
create table selection_good as select * from selection
where grade >= 80;
select * from selection_good;
insert into selection_good select * from selection
where grade >= 70;
select * from selection_good;




use mysql;
update user set host = '%' where user = 'root';
flush privileges;
show global variables like 'port';

mysql -h 10.56.10.46 -P 3306 -u root -p
-- mysql -h 192.168.181.254 -p 3306 -u root -p
-- 可以本地和远程同时登陆


-- 笔记本
mysql -h 10.101.11.196 -P 3306 -uroot -p


mysqldump -h 10.101.11.196 -P 3306 -uroot -p123456 t001 > E:\Notes\Notes_Latex\MySQL_study\Codes\t002.sql


create view employee_view as
select employee.ename as employee_ename, employee.job as job, department.dname as department_name
from employee inner join department
on employee.dept_deptid = department.deptid;
-- 会根据查询结果生成新的视图，一般不要修改视图
-- 利用sql studio，实现表的复制与还原
drop view 名称


-- 索引 会提高查询速度，以空间换速度
create index name on employee(ename);

select * from employee where ename = 'li si';

-- 不支持索引的：
select * from employee where ename like 'li%';
select * from employee order by ename;



select now();
select length('名字：zhangqr');
select ucase('abc');
select * from employee where left(name, 1) = 'li';