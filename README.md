# controls-ui

### 效果

![](https://img-blog.csdnimg.cn/direct/fc005823352c4ff88c90bf2b8b863767.gif#pic_center)

### 使用

方法一：将`  comm/toast, comm/message, /resource/imgs`拷至项目中引入头文件使用

方法二：下载发行包`lib**.dll lib**.dll.a`，将需要的头文件【`toast.h message.h`】放至项目中，将`litb.**.dll放至构建的目录中【可执行文件.exe】

在cmake.txt增加如下代码：

```cmake
#include 存放 toast.h message.h 文件
#CMAKE_CURRENT_SOURCE_DIR 当前项目绝对路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# 引入 .a 文件
target_link_libraries(project_name PRIVATE Qt5::Widgets ${CMAKE_CURRENT_SOURCE_DIR}/lib/libmessage.dll.a )
```

