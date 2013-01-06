<?php

/**
 * @file
 * 每个Arial请求都必须加载的一些函数
 */

/**
 * 当前系统版本
 */
define('VERSION', '1.0');

/** 
 * 核心API兼容性
 */
define('ARIAL_CORE_COMPATIBILITY', '1.x');

/**
 * 最小支持的PHP版本
 */
define('ARIAL_MINIMUM_PHP', '5.2.4');

/**
 * PHP memory_limit 最小推荐值
 */
define ('ARIAL_MINIMUM_PHP_MEMORY_LIMIT', '32M');

/**
 * 错误报告级别: 不显示错误
 */
define ('ERROR_REPORTING_HIDE', 0);

/**
 * 错误报告级别: 显示错误和警告信息
 */
define ('ERROR_REPORTING_DISPLAY_SOME', 1);

/**
 * 错误报告级别: 显示所有信息
 */
define ('ERROR_REPORTING_DISPLAY_ALL', 2);

/**
 * 表示该项目不应该被删除，除非显示的选择
 * 使用 缓存ID 通过cache_clear_all()函数可以删除该项目
 */
define ('CACHE_PERMANENT', 0);

/**
 * 表示该项目下次启动时清除缓存信息
 */
define ('CACHE_TEMPORARY', -1)

/**
 * @degroup logging_serverity_levels 记录严重性级别开始
 * @{
 * 在RFC 3164 中已经定义了严重性级别
 *
 * 在RFC 3164第4.1.1节使用WATCHDOG_*常量定义了对应的日志严重性级别
 * PHP 提供了预定义的LOG_*常量，用于在Windows版本中的syslog()函数，但它们的值不对应于RFC3164
 * 相关的PHP错误报告的评论已经关闭，这不是一个错误，Windows仅需要较少的日志记录水平，
 * 因此你看到的行为完全正常。
 * @see http://www.faqs.org/rfcs/rfc3164.html
 * @see http://bugs.php.net/bug.php?id=18090
 * @see http://php.net/manual/function.syslog.php
 * @see http://php.net/manual/network.constants.php
 * @see watchdog()
 * @see watchdog_serverity_levels()
 */

/**
 * 日志消息的严重程度 -- 紧急: 系统不可用
 */
define ('WATCHDOG_EMERGENCY', 0);

/** 
 * 日志消息的严重程度 -- 警告: 必须立即采取行动
 */
define ('WATCHDOG_ALERT', 1);

/**
 * 日志消息的严重程度 -- 关键条件
 */
define ('WATCHDOG_CRITICAL', 2);

/**
 * 日志消息的严重程度 -- 错误条件
 */
define ('WATCHDOG_ERROR', 3);

/**
 * 日志消息的严重程度 -- 警告条件
 */
define ('WATCHDOG_WARNING', 4);

/**
 * 日志消息的严重程度 -- 正常但重要条件
 */
define ('WATCHDOG_NOTICE', 5);

/**
 * 日志消息的严重程度 -- 信息性消息
 */
define ('WATCHDOG_INFO', 6);

/**
 * 日志消息的严重程度 -- 调试级信息
 */
define ('WATCHDOG_DEBUG', 7);

/**
 * @} 日志消息严重程度定义结束
 */

/**
 * 启动第一阶段: 初始化配置 
 */
define ('ARIAL_BOOTSTRAP_CONFIGUARTION', 0);

/**
 * 启动第二阶段: 尝试缓存页面
 */
define ('ARIAL_BOOTSTRAP_PAGE_CACHE', 1);

/**
 * 启动第三阶段: 初始化数据库层
 */
define ('ARIAL_BOOTSTRAP_DATABASE', 2);

/**
 * 启动第四阶段: 初始化系统变量
 */
define ('ARIAL_BOOTSTRAP_SESSION', 3);

/**
 * 启动第五阶段: 初始化会话句柄
 */
define ('ARIAL_BOOTSTRAP_SESSION', 4);

/**
 * 启动第六阶段: 设置页面标题
 */
define ('ARIAL_BOOTSTRAP_PAGE_HEADER', 5);

/**
 * 启动第七阶段: 找出页面语言
 */
define ('ARIAL_BOOTSTRAP_LANGUAGE', 6);

/**
 * 启动最后阶段: Arial全部加载完毕，验证和修复输入数据
 */
define ('ARIAL_BOOTSTRAP_FULL', 7);

/**
 * 匿名用户的ID，匹配数据库'role'表的值
 */
define ('ARIAL_ANONYMOUS_RID', 1);

/**
 * 认证用户的ID， 匹配数据库'role'表的值
 */
define ('ARIAL_AUTHENTICATED_RID', 2);

/**
 * 千字节数设置
 * 请访问 http://en.wikipedia.org/wiki/Kilobyte 获取更多信息
 */
define ('ARIAL_KILOBYTE', 1024);

/**
 * 当没有明确指定语言代码时，使用的语言代码
 * 使用 ISO639-2 定义的"Undetermined"
 */
define ('LANGUAGE_NONE', 'und');

/**
 * 使用的语言来定义的内容语言的类型。
 */
define ('LANGUAGE_TYPE_CONTENT', 'language_content');

/**
 * 选择用户界面使用的语言类型
 */
define ('LANGUAGE_TYPE_INTERFACE', 'language');

/**
 * URLs使用的语言类型
 */
define ('LANGUAGE_TYPE_URL', 'language_url');

/**
 * 从左到右书写语言，$language->direction的可能值
 */
define ('LANGUAGE_LTR', 0);

/**
 * 从右到左书写语言，$language->direction的可能值
 */
define ('LANGUAGE_RTL', 1);

/**
 * 当前请求的UNIX纪元
 * 和$_SERVER['REQUEST_TIME']的区别是自PHP5.4.0以来是一个浮点数
 * 大部分的PHP函数拒绝浮点数的时间戳。
 * 包括 date_create()
 * 
 * @see http://php.net/manual/reserved.variables.server.php
 * @see http://php.net/manual/function.time.php
 */
define ('REQUEST_TIME', (int) $_SERVER['REQUEST_TIME']);

/**
 * arial_set_title标志，使用check_plain()对文字进行转换格式
 */
define ('CHECK_PLAIN', 0);

/** 
 * arial_set_title标志, 文本已经转换了格式
 */
define ('PASS_THROUGH', -1);

/**
 * 重置注册表查找缓存的信号
 */
define ('REGISTRY_RESET_LOOKUP_CACHE', 1);

/**
 * 应该被写入注册表查找缓存存储的信号
 */
define ('REGISTRY_WRITE_LOOKUP_CACHE', 2);

/**
 * PHP正则表达式匹配函数名
 * @see http://php.net/manual/en/language.functions.php
 */
define ('ARIAL_PHP_FUNCTIONS_PATTERN', '[a-zA-Z_\x7f-\xff][a-zA-Z0-9_\x7f-\xff]*');

/**
 * 提供可用于大型阵列结构的一个缓存包装器
 * 这个类应该被扩展，需要缓存大量的系统的数据，并表示为一个数组来调用函数
 * 这个数组会变得非常的大，因此随着时间的推移ArrayAccess接口被用作不同接口的
 * 策略，以用于内部缓存(延迟加载，构建高速缓存等等)。
 * 这可以极大地减少数据量，需要加载缓存对每个请求的后端，从静态缓存相同的数据
 * 和内存使用情况。
 * 需要注意的是array_*功能不起作用与ArrayAccess接口。
 * 系统应该只是内部使用ArialCacheArray，如果提供的API函数需要返回全部数组，
 * 可以被单独缓存或直接返回。
 * 然而，由于ArialCacheArray持有部分内容设计，它应该是一个普通的PHP数组
 * 或者包含全部结构。
 * 还要注意的是，由于PHP5.3.4之前的限制，这是不可能直接写入到包含在此对象的
 * 嵌套的数组的内容。
 * 仅写入到顶层的数组元素是可能的。
 * 因此，如果你以前设置的对象 $object['foo'] = array(1, 2, 'bar' => 'baz'),要修改该对象的'bar'的值'baz'为'foobar',不能这样修改$object['foo']['bar'] = 'foobar'.相反，你必须使用新的对象$object['foo'] = array(1, 2, 'bar' => 'foobar')覆盖整个$object['foo']对象。
 * 由于这个相同的限定，尝试创建引用到任何包括数据，嵌套或其他方式都将失败。
 * 因此$var = &$object['foo']将不抛出错误，并且$var的数据将被$object对象填充,
 * 但该数据将被传值，而不是引用传递。 
 * 查看PHP官方文档获取更多的信息. 
 * http://php.net/manual/en/arrayaccess.offsetget.php on
 * ArrayAccess::offsetGet()
 *
 * 默认情况下，缓存调用函数可能会要求在阵列中不会存在，
 * 即使在高速缓存重建键的类账户。
 * 这可以防止高速缓存重建的情况下,因为一个丢失的元素一遍又一遍的触发。
 * 这些情况在内部存储为NULL值。
 * 这意味着，在offsetGet（）和offsetExists（）方法必须被覆盖，
 * 如果缓存一个数组，最佳的值应该是NULL,$object->offsetExists()
 * 需要被正确的返回(相当于array_key_exists()和isset()函数)。
 * 在大多数情况下，这不应该是必要的。 
 * 扩展这个类必须至少重写resolveCacheMiss()方法并实现该方法。
 * 默认情况下，该类的offsetSet()这个方法是不会被覆盖的。
 * 实际上，这意味着分配的偏移量通过ArrayAccess接口将只适用的范围和对象是不会
 * 被写回永久性缓存。
 * 这类似于程序代码的静态或持久的缓存模式.
 * 扩展一个类可能希望更改这种行为,例如重写offsetSet()和增加自动调用persist()功能.
 *
 * @see SchemaCache
 */
abstract class ArialCacheArray implements ArrayAccess {
  /**
   * 缓存 cid | cache_set() 和 cache_get()
   */
  protected $cid;

  /**
   * 缓存 bin | cache_set() 和 cache_get()
   */
  protected $bin;

  /**
   * 数组的键可添加到在请求结束高速缓存
   */
  protected $keysToPersist = array();

  /**
   * 存储的数据本身
   */
  protected $storage = array();

  /**
   * 构建ArialCacheArray对象
   *
   * @param $cid
   *   缓存的cid
   * @param $bin
   *   使用bin缓存数据内容
   */
  public function __construct($cid, $bin) {
    $this->cid = $cid;
    $this->bin = $bin;
/////////////////// cache_get 未定义 ///////////////////////
    if ($cached = cache_get($this->cid, $this->bin)) {
      $this->storage = $cached->data;
    }
  }

  /**
   * 重写ArrayAccess::offsetExists()
   */
  public function offsetExists($offset) {
    return $this->offsetGet($offset) !== NULL;
  }

  /**
   * 重写ArrayAccess::offsetGet()
   */
  public function offsetGet($offset) {
    if (isset($this->storage[$offset]) || array_key_exists($offset, $this->storage)) {
      return $this->storage[$offset];
    }
    else {
      return $this->resolveCacheMiss($offset);
    }
  }

  /**
   * 重写ArrayAccess::offsetSet()
   */
  public function offsetSet($offset, $value) {
    $this->storage[$offset] = $value;
  }

  /**
   * 重写ArrayAccess::offsetUnset()
   */
  public function offsetUnset($offset) {
    unset($this->storage[$offset]);
  }
}
