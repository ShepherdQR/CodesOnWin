
# This file is built on Jan. 8th, 2020.
# 

# T001 数据库创建等的操作

CREATE DATABASE t007;
SHOW DATABASES;
SHOW CREATE DATABASE t007;
ALTER DATABASE t007 DEFAULT CHARACTER SET 'gbk';
SHOW CREATE DATABASE T007;
DROP DATABASE IF EXISTS t007;

CREATE DATABASE t007 DEFAULT CHARACTER SET 'gbk';
SHOW CREATE DATABASE t007;
ALTER DATABASE t007 DEFAULT CHARACTER SET 'utf8';
SHOW CREATE DATABASE t007;

USE t007;
SELECT DATABASE();
DROP DATABASE IF EXISTS t007;
SHOW DATABASES;







