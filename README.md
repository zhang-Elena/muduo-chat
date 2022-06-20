# 基于muduo库的聊天服务器开发

#### 介绍
本项目是基于muduo库的集群聊天服务器开发

#### 技术栈
1. 采用muduo网络库作为项目的网络核心模块，提供高并发的网络IO服务、网络和业务模块代码
2. 采用json作为私有通信协议
3. 使用mysql关系型数据库存储项目数据
4. 使用连接池提高数据库的数据存取
5. 配置nginx进行负载均衡，实现聊天服务器集群功能
6. 采用redis，实现跨服务器通信


#### 环境

centos7.6 vecode cmake muduo库 boost库 nginx redis mysql mysql-client



