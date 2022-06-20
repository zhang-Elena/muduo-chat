#include "groupmodel.hpp"
#include "db.h"

//创建群组
bool GroupModel::createGroup(Group &group){
    char sql[1024] = {0};
    sprintf(sql, "insert into AllGroup(groupname,groupdesc) values('%s','%s')",
           group.getName().c_str(),group.getDesc().c_str());
    
    MySQL mysql;
    if(mysql.connect()){
        if(mysql.update(sql)){
            group.setId(mysql_insert_id(mysql.getConnection()));
            return true;
        }
    }
    return false;
}

//加入群组
void GroupModel::addGroup(int userid, int groupid, string role){
    char sql[1024] = {0};
    sprintf(sql, "insert into GroupUser values(%d,%d,'%s')",
           groupid,userid,role.c_str());
    
    MySQL mysql;
    if(mysql.connect()){
        mysql.update(sql);
    }
}

//查询用户所在群组信息
vector<Group> GroupModel::queryGroups(int userid){
    /**
     * 1. 先根据userid在groupuser表中查询出该用户所属的群组信息
     * 2. 在根据群组信息，查询属于该群组的所有用户的userid，并且和user表进行多表联合查询，查出用户的详细信息
    */
    char sql[1024] = {0};
    sprintf(sql, "select a.id,a.groupname,a.groupdesc from AllGroup a inner join \
        GroupUser b on b.groupid = a.id where b.userid=%d", userid);

    vector<Group> groupVec;
    MySQL mysql;
    if(mysql.connect()){
        MYSQL_RES *res = mysql.query(sql);
        if(res != nullptr){
            //把userid用户的离线消息放入vec中返回
            MYSQL_ROW row;
            while((row = mysql_fetch_row(res)) != nullptr){
                Group group;
                group.setId(atoi(row[0]));
                group.setName(row[1]);
                group.setDesc(row[2]);
                groupVec.push_back(group);
            }
            mysql_free_result(res);
        }
    }

    //查询群组的用户信息
    for(Group &group : groupVec){
        sprintf(sql, "select a.id,a.name,a.state,b.grouprole from User a inner join \
        GroupUser b on b.userid = a.id where b.groupid=%d", group.getId());

        MYSQL_RES *res = mysql.query(sql);
        if(res != nullptr){
            //把userid用户的离线消息放入vec中返回
            MYSQL_ROW row;
            while((row = mysql_fetch_row(res)) != nullptr){
                GroupUser user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setState(row[2]);
                user.setRole(row[3]);
                group.getUsers().push_back(user);
            }
            mysql_free_result(res);
        }
    }
    return groupVec;
}

//根据指定的groupid查询群组用户的id列表，除userid自己，主要用户群聊业务给群组其他成员群发消息
vector<int> GroupModel::queryGroupUsers(int userid, int groupid){
    char sql[1024] = {0};
    sprintf(sql,"select userid from GroupUser where groupid = %d and userid != %d",groupid, userid);

    vector<int> idVec;
    MySQL mysql;
    if(mysql.connect()){
        MYSQL_RES *res = mysql.query(sql);
        if(res != nullptr){
            MYSQL_ROW row;
            while((row = mysql_fetch_row(res))!= nullptr){
                idVec.push_back(atoi(row[0]));
            }
            mysql_free_result(res);
        }
    }
    return idVec;
}