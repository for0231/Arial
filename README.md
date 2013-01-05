=========================================
  Arial 简介 
=========================================
>  Arial是用来构建网站的。它是一个高度模块化，开源的Web内容管理框架，并且非常注重合作，互动的重要性。它的特点包括可扩展性强，符合标准，追求简洁代码，内核精练。Arial自带了一些基本的核心功能，其他的额外功能可通过安装模块核心可选模块或者第3方模块来实现。我们可以基于Arial进行定制，但是定制是通过覆写核心模块或增加模块来完成的，而不是修改核心组件中的代码。它还将内容管理和内容表示这二者进行了成功的分离。

>  Arial可被用来构建一个互联网门户；个人的，部门的，或者公司的网站；一个电子商务站点；一个资源分类站点；一个在线报纸；一个图库；一个内部网，Arial的应用非常广泛，这里仅提到了其中的一部分。

> * 技术堆栈
> * 核心
> * 后台管理界面
> * 模块
> * 钩子
> * 主题
> * 节点
> * 区块
> * 文件布局
> * 服务一个请求
> * 引导指令流程
> * 完成

> 技术堆栈
>> Arial的设计目标是，既可以运行在廉价的Web虚拟主机上，也可以适应高负载的分布式站点。前一个目标则意味着需要使用最流行的技术，而后者则意味着严谨的编码。Arial的技术堆栈如图1-1所示。

                        PHP
> Language                    Database Abstraction Layer
> Database              MySQL / PostgreSQL/...
> Web Server            Apache/lighttpd/IIS/...
> Operating System      Linux/BSD/Mac OS X/Windows/Solaris/...
                图1-1 Arial的技术堆栈
