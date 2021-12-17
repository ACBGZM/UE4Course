# UE4Course



第一次作业：01/FPSProject



具有以下功能：

- 基本移动
- 核心玩法，开枪、摧毁特定Actor
- 一些交互，包括按键扣血（仅）、按键暂停、按键换子弹
- 结束游戏逻辑，满足其一即可
  - 子弹（包括后备子弹）全打完
  - 站到特殊地面上
  - 摧毁全部10个漂浮方块
- UI
  - 主菜单：可以开始游戏，可以退出
  - 暂停菜单：可以继续游戏，可以返回主菜单
  - 结束画面：显示本局评分，可以返回主菜单
  - HUD：显示子弹数，显示游戏玩法提示
  
  
---



第二次作业：02/TPSProject



具有以下功能：

- 角色的若干行为：八方向移动、跳跃、下蹲、快跑、开枪、换弹、精确瞄准
- 渲染效果：第二把武器的渐变彩色材质、镜头景深效果
- 游戏玩法
  - 游戏目标：四处走动，用子弹打到紫色靶子
  - 结束游戏（满足其一）：
    - 血量掉到0
    - 站到特殊地面上
    - 摧毁全部15个漂浮方块
  - 交互物件
    - 黄色漂浮方块：碰到后加子弹
    - 红色地板：碰到后扣血（优先扣护甲）
    - SK_Gun：碰到后获得副武器
    - 彩色地板：碰到后结束游戏
- UI
  - HUD：显示装备的武器信息、玩家的一些属性、其他一些操作提醒，进行游戏流程提示
  - 主菜单：可以开始游戏、查看操作提示、退出
  - 暂停菜单：可以继续游戏、返回主菜单
  - 结束画面：显示本局评分，可以返回主菜单



---



第三次作业：TPSProject



以之前的项目为基础，制作了三个关卡：

- 单人闯关（教学）
  - 跟第二次的项目相同，通过Notice告知玩家各种操作方式，玩家击中所有15个紫色靶子则通关游戏
- 单人闯关（AI对战）
  - 游戏目的依然是击中所有15个靶子
  - 有白色Bot和僵尸两种Enemy，两种Enemy在看到玩家后会追随玩家，靠近玩家后会进行攻击
    - 白色Bot移动速度较快，使用膝盖攻击，攻击力较低
    - 僵尸移动速度较慢，攻击力较高；半血以下进入狂暴模式，移速加快、攻击力提高
- 双人合作
  - 一名玩家创建房间后，其他玩家可以加入这个房间
  - 每个玩家的各种动作、发射的子弹等会进行同步；地图内一些物品的运动情况会同步给所有玩家
  - 有一些地图内可拾取的物品，被任意一个玩家拾取后就消失
  - 放置了两个防御力强化的僵尸和一群Bot，玩家可以共同对这些Enemy造成伤害



---

