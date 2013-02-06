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

  /**
   * 标志永久缓存的偏移值
   * 如果通过cache对象的offsetSet()设定了一个值,默认情况下,
   * 它不会被永久保存在缓存中,除非通过这个方法设定.
   * 在请求的时间内,这将允许被缓存,而没有必要在最后写入到持久缓存中
   * 
   * @param $offset
   *   被请求的数组偏移量
   * @param $persist
   *   Bool值,是否指定永久缓存,默认为TRUE,当$persist=FALSE时,取消标志,
   * 因此它不会写入到最后的请求中
   */
  public function persist($offset, $persist = TRUE) {
    $this->keysToPersist[$offset] = $persist;
  }

  /**
   * 解决丢失的缓存数据
   * 当在对象中没有找到偏移量值时,将被当作缓存丢失.
   * 这个方法允许类实现接口,查询真实值并允许将它缓存
   *
   * @param $offset
   *   被请求的数组偏移量
   * 
   * @return 
   *   偏移量值,没有值时为空
   */

  abstract protected function resolveCacheMiss($offset);

  /**
   * 立即写入缓存
   * 
   * @param $data
   *   被写入缓存的数据
   * @param $lock
   *   写入缓存之前是否加锁
   */
  protected function set($data, $lock = TRUE) {
    // 锁定缓存写入,避免发生冲突
    // 重写__construct,实现对丢失的缓存的锁定
    $lock_name = $this->cid . ':' . $this->bin;
    if (!$lock || lock_acquire($lock_name)) {
      if ($cached = cache_get($this->cid, $this->bin)) {
        $data = $cached->data + $data;
      }
      cache_set($this->cid, $data, $this->bin);
      if ($lock) {
        // lock_release 未定义
        lock_release($lock_name);
      }
    }
  }
  /**
   * 销毁ArialCacheArray对象
   */
  public function __destruct() {
    $data = array();
    foreach ($this->keysToPersist as $offset => $persist) {
      if ($persist) {
        $data[$offset] = $this->storage[$offset];
      }
    }
    if (!empty($data)) {
      $this->set($data);
    }
  }
}

/**
 * 指定名字开始计时
 * 
 * 如果您启动和停止的同一个定时器多次，测量的时间间隔将进行累积。
 *
 * @param $name 
 *   计时器名字
 */
function timer_start($name) {
  global $timers;

  $timers[$name]['start'] = microtime(TRUE);
  $timers[$name]['count'] = isset($timers[$name]['count']) ? ++$timers[$name]['count'] : 1;
}

/**
 * 读取定时器的当前值，而无需停止定时器。
 *
 * @param $name
 *    计时器名字
 *
 * $return 
 *    目前计时器的值,以ms为单位
 */
function timer_read($name) {
  global $timers;

  if (isset($timers[$name]['start'])) {
    $stop = microtime(TRUE);
    $diff = round(($stop - $timers[$name]['start']) * 1000, 2);

    if (isset($timers[$name]['time'])) {
      $diff += $timers[$name]['time'];
    }
    return $diff;
  }
  return $timers[$name]['time'];
}

/**
 * 停止指定计时器
 * 
 * @param $name
 *   计时器的名字
 * 
 * @return 
 *    计时器数组,该数组包含定时器已经启动和停止（计数）的次数
 * 和累计在ms毫秒（时间）的定时器值。
 */
function timer_stop($name) {
  global $timers;

  if (isset($timers[$name]['start'])) {
    $stop = microtime(TRUE);
    $diff = round(($stop - $timers[$name]['start']) * 1000, 2);
    if (isset($timers[$name]['time'])) {
      $timers[$name]['time'] += $diff;
    }
    else {
      $timers[$name]['time'] = $diff;
    }
    unset($timers[$name]['start']);
  }

  return $timers[$name];
}

/**
 * 返回一个合适的配置目录
 * 
 * 返回配置目录路径,基于网站的主机名,端口和路径名
 * 查看default.settings.php示例,URL是怎样转换成一个目录的.
 *
 * @param bool $require_settings
 *  仅配置目录与现有的settings.php文件将被确认。
 * 在安装初始化期间,这默认设置为false,因此Arial能够匹配目录,然后在里面
 * 创建一个新的settings.php文件.
 * 
 * @param bool $reset
 *  强制一个完整的搜索匹配的目录，即使被发现以前。默认为false。
 * 
 * @return 
 *  返回匹配的目录地址
 * 
 * @see default.settings.php
 */
function conf_path($require_settings = TRUE, $reset = FALSE) {
  $conf = &arial_static(__FUNCTION__, '');

  if ($conf && !$reset) {
    return $conf;
  }

  $confdir = 'sites';
  
  $sites = array();
  if (file_exists(ARIAL_ROOT . '/' . $confdir . 'sites.php')) {
    // 这将覆盖网站所需的映射。
    include(ARIAL_ROOT . '/' . $confdir . '/sites.php');
  }

  $uri = explode('/', $_SERVER['SCRIPT_NAME'] ? $_SERVER['SCRIPT_NAME'] : $_SERVER['SCRIPT_FILENAME']);
  $server = explode('.', implode('.', array_reverse(explode(':', rtrim($_SERVER['HTTP_HOST'], '.')))));

  for ($i = count($uri) - 1; $i > 0; $i--) {
    for ($j = count($server); $j > 0; $j--) {
      $dir = implode('.', array_slice($server, -$j)) . implode('.', array_slice($uri, 0, $i));
      if (isset($sites[$dir]) && file_exists(ARIAL_ROOT . '/' . $confdir . '/' . $sites[$dir])) {
        $dir = $sites[$dir];
        return $conf;
      }
    }
  }
  $conf = "$confdir/default";

  return $conf;
}

/**
 * 设置相应的服务器所需的变量，以便命令行脚本的工作。
 * 在Arial启动之前,这个函数能够通过命令行调用,确认页面加载了系统所需参数
 * 这是因为Arial的许多部分假定它们都运行在浏览器上,当Arial运行在命令行运行时,从PHP的全局变量$_SERVER获取信息.
 * 在许多情况下，此函数的默认方式填充的$ _SERVER变量是足够的，
 * 因此，它可以被称为不传递任何输入的情况下,使用命令行模式.
 * 然而，命令行脚本运行在一个多点安装（或任何安装的settings.php
 * 存储之外的其他地方的网站/默认文件夹）需要通过在网站的网址，
 * 让Arial能够检测到正确的位置的settings.php文件。
 * 在“网址”参数传递也需要request_uri()等函数返回的预期值。
 * 大多数其他参数并不需要通过的，但可能在某些情况下是必要的，
 * 例如，如果Drupal的的IP_ADDRESS（）函数需要返回任何东西，
 * 但标准localhost值（'127 .0.0.1'），
 * 命令行脚本通过'REMOTE_ADDR'键，通过所需的值。
 *
 * @param $variables
 *  (可选) 代替$_SERVER的关联数组变量,如果$variables['url']存在,
 *  它将被用作填充服务器的默认值,它应该被设置为当前页面请求的URL
 *  但不包括$_GET请求信息除了包含脚本名称.
 * 
 * @see conf_path()
 * @see request_uri()
 * @see ip_address()
 */
function arial_override_server_variables($variables) {
  // 允许使用URL提供的值重写$_SERVER中已经存在的任何值.
  if (isset($variables['url'])) {
    $url = parse_url($variables['url']);
    if (isset($url['host'])) {
      $_SERVER['HTTP_HOST'] = $url['host'];
    }
    if (isset($url['path'])) {
      $_SERVER['SCRIPT_NAME'] = $url['path'];
    }
    unset($variables['url']);
  }
  // 定义$_SERVER的默认键,如果$_SERVER没有定义这些键和
  // 没有传递相应参数的时候.
  $defaults = array(
    'HTTP_HOST' => 'localhost',
    'SCRIPT_NAME' => NULL,
    'REMOTE_ADDR' => '127.0.0.1',
    'REQUEST_METHOD' => 'GET',
    'SERVER_NAME' => NULL,
    'SERVER_SOFTWARE' => NULL,
    'HTTP_USER_AGENT' => NULL,
  );
  // 替换相应的$_SERVER数组
  $_SERVER = $variables + $_SERVER + $defaults;
}

/** 
 * 初始化PHP环境变量
 */
function arial_environment_initialize() {
  if (!isset($_SERVER['HTTP_REFERER'])) {
    $_SERVER['HTTP_REFERER'] = '';
  }
  if (!isset($_SERVER['SERVER_PROTOCOL']) || ($_SERVER['SERVER_PROTOCOL'] != 'HTTP/1.0' && $_SERVER['SERVER_PROTOCOL'] != 'HTTP/1.1')){
    $_SERVER['SERVER_PROTOCOL'] = 'HTTP/1.0';
  }

  if (isset($_SERVER['HTTP_HOST'])) {
    // HTTP_HOST是用户输入，确保只允许在主机名中包含的字符。
    // 查看RFC 952 和 RFC 2181
    // $_SERVER['HTTP_HOST']这里是小写的每规格
    $_SERVER['HTTP_HOST'] = strtolower($_SERVER['HTTP_HOST']);
    if (!arial_valid_http_host($_SERVER['HTTP_HOST'])) {
      // HTTP_HOST是无效的,例如,包括斜线,它将是一次攻击
      header($_SERVER['SERVER_PROTOCOL'] . '400 Bad Request');
      exit;
    }
  }
  else {
    // 一些pre-HTTP/1.1客户端不会发送主机头,确保已经定义为有效的
    $_SERVER['HTTP_HOST'] = '';
  }
  
  // 当为简洁URL启用时,如请求为?q=foo/bar时,这是不可能的追加查询
  // 字符串中使用mod_rewrite没有B标志(B标志从Apache 2.2.8开始加入.
  // 因为在传递给PHP之前会被mod_rewrite反转解析,一些特殊字符如"&"
  // "%"在URL中必须编码
  $_GET['q'] = request_path();

  // 强制E_ALL，但允许用户设置水平不是E_ALL的一部分，
  error_reporting(E_ALL | error_reporting());

  // 重写PHP设置,需要Arial正常的工作.
  // sites/default/default.settings.php包含多个运行的设置
  // 文件.htaccess不能在运行时更改
  // 从数据库或文件读取时,不要转义斜线
  ini_set('magic_quotes_runtime', '0');
  // 使用session,cookies时,不要在查询字符中使用明文传输
  ini_set('session.use_cookies', '1');
  ini_set('session.use_only_cookies', '1');
  ini_set('session.use_trans_sid', '0');
  // 不要使用PHP会话发送HTTP头信息
  ini_set('session.cache_limiter', 'none');
  // 使用httponly　sesson cookies.
  ini_set('session.cookie_httponly', '1');

  // 设置健全的区域设置，以确保一致的字符串，日期，时间和数字处理。
  setlocale(LC_ALL, 'C');
}

/**
 * 验证主机名,例如$_SERVER['HTTP_HOST']是安全的.
 *　
 * @return 
 *    只有包含已经定义的字符才是安全的,置状态为TRUE,否则为假,置FALSE
 */
function arial_valid_http_host($host) {
  return preg_match('/^\[?(?:[a-zA-Z0-9-:\]_]+\.?)+$/', $host);
} 

/**
 * 设置基本URL，Cookie域，从配置和会话名。
 */
function arial_settings_initialize() {
  global $base_url, $base_path, $base_root;

  // 从全局的命名空间导出settings.php的变量
  global $databases, $cookie_domain, $conf, $installed_profile, $update_free_access, $db_url, $db_prefix, $arial_hash_salt, $is_https, $base_secure_url, $base_insecure_url;
  $conf = array();

  if (file_exists(ARIAL_ROOT . '/' . conf_path(). '/settings.php')) {
    include_once ARIAL_ROOT . '/' . conf_path(). '/settings.php';
  }
  $is_https = isset($_SERVER['HTTPS']) && strtolower($_SERVER['HTTPS']) == 'on';
  
  if (isset($base_url)) {
    // 从settings.php解析基础URL
    $parts = parse_url($base_url);
    $http_protocol = $parts['scheme'];
    if (!isset($parts['path'])) {
      $parts['path'] = '';
    }
    $base_path = $parts['path'] . '/';
    // 构建 $base_root,直到"scheme://之后的第一个'/'
    $base_root = substr($base_url, 0, strlen($base_url) - strlen($parts['path']));
  }
  else {
    // 创建基础URL
    $http_protocol = $is_https ? 'https' : 'http';
    $base_root = $http_protocol . '://' . $_SERVER['HTTP_HOST'];

    $base_url = $base_root;
    // $_SERVER['SCRIPT_NAME']
    if ($dir = rtrim(dirname($_SERVER['SCRIPT_NAME']), '\/')) {
      $base_path = $dir;
      $base_url .= $base_path;
      $base_path .= '/';
    }
    else {
      $base_path = '/';
    }
  }
  $base_secure_url = str_replace('http://', 'https://', $base_url);
  $base_insecure_url = str_replace('https://', 'http://', $base_url);

  if ($cookie_domain) {
    // 如果用户指定了cookie域名,也同样用到session的名字上
    $session_name = $cookie_domain;
  }
  else {
    // 否则使用$base_url 作为session名字,通过HTTP和HTTPS协议而不使用相同的会话名称
    list( , $session_name) = explode('://', $base_url, 2);
    // 由访问者，HTTP_HOST可以进行修改,我们已经在arial_settings_initialize()中过滤了安全性问题.
    if (!empty($_SERVER['HTTP_HOST'])) {
      $cookie_domain = $_SERVER['HTTP_HOST'];
      //从cookie.domain中过滤'www.',端口号
      $cookie_domai = ltrim($cookie_domain, '.');
      if (strpos($cookie_domain, 'www.') === 0 ) {
        $cookie_domain = substr($cookie_domain, 4);
      }
      $cookie_domain = explode(':', $cookie_domain);
      $cookie_domain = '.' . $cookie_domain[0];
    }
  }
  // 在RFC2109中,cookie 域名必须包含至少一个点,例如'localhost'或IP地址的主机没有设置cookie的域.
  if (count(explode('.', $cookie_domain)) > 2 && !is_numeric(str_replace('.', '', $cookie_domain))) {
    ini_set('session.cookie_domain', $cookie_domain);
  }
  // 为了防止被劫持的会话cookie，用户可以配置
  // 他们的网站的SSL版本只通过SSL传输会话cookie
  // 使用PHP的session.cookie_secure设置。浏览器将使用两个
  // 单独的会话cookie的网站的HTTPS和HTTP版本。因此，我们
  // 必须使用不同的HTTPS和HTTP会话标识符，以防止
  // cookie的碰撞。
  if ($is_https) {
    ini_set('session.cookie_secure', TRUE);
  }
  $prefix = ini_get('session.cookie_secure') ? 'SSESS' : 'SESS';
  session_name($prefix . substr(hash('sha256', $session_name), 0, 32));
}

/**
 * 返回，并选择性地设定系统资源的文件名。
 * 文件名，是否提供，高速缓存或从数据库中检索，只返回该文件是否存在
 * 此功能允许Arial的资源（模块和主题）设在不同的地方，
 * 这取决于站点的配置中起着关键的作用。例如，可以合法地设在
 * 这三个地方中的任何一个模块'foo'的：
 * 
 * modules/foo/foo.module
 * sites/all/modules/foo/foo.module
 * sites/example.com/modules/foo/foo.module
 *
 * 调用arial_get_filename('module', 'foo'),基于模块的位置,
 * 将会给出上面中的一个.
 * 
 * @param $type
 *  元素类型,例如,theme, theme_engine, module, profile等等.
 * @param $name 
 *  请求的名字
 * @param $filename
 *  元素的文件名,如果它是被显示设置的,而不是通过请求数据库
 * @return 
 *  返回请求的文件名
 */
function arial_get_filename($type, $name, $filename) {
  //请求期间,文件的位置不会变更,因此不要使用arial_static
  static $files = array(), $dirs = array();

  //配置文件是一种特殊情况：他们有一个固定的位置和命名。
  if ($type == 'profile') {
    $profile_filename = "profiles/$name/$name.profile";
    $files[$type][$name] = file_exists($profile_filename) ? $profile_filename : FALSE;
  }
  if (!isset($files[$type])) {
    $files[$type] = array();
  }

  if (!empty($filename) && file_exists($filename)) {
    $files[$type][$name] = $filename;
  }
  elseif (isset($files[$type][$name])) {
    // nothing
  }
  // 验证，我们有一个活动的数据库连接，然后再查询数据库。
  // 这是必需的，因为这个函数被调用之前，我们两个有一个
  // 数据库连接（即在安装过程中），当一个数据库连接失败。 
  else {
    try {
      if (function_exists('db_query')) {
        $file = db_query("SELECT filename FROM {system} WHERE name = :name AND type = :type", array(':name' => $name, ':type' => $type))->fetchField();
        if (file_exists(ARIAL_ROOT . '/' . $file)) {
          $files[$type][$name] = $file;
        }
      }
    }
    catch (Exception $e) {
      //数据库表可能不存在，因为Drupal尚未安装，
      //或数据库可能会卸载。我们有一个后备对于这种情况，
      //所以我们完全隐藏错误。 
    }
    if (!isset($files[$type][$name])) {
      //我们有一个一致的目录命名：模块，主题...
      $dir = $type . 's';
      if ($type == 'theme_engine') {
        $dir = 'themes/engines';
        $extension = 'engine';
      }
      elseif ($type == 'theme') {
        $extension = 'info';
      }
      else {
        $extension = $type;
      }

      if (!isset($dirs[$dir][$extension])) {
        $dirs[$dir][$extension] = TRUE;
        if (!function_exists('arial_system_listing')) {
          require_once ARIAL_ROOT . '/includes/common.inc';
        }
        // 扫描相应的目录中的所有文件所要求的扩展，
        // 而不是仅仅是我们正在寻找的文件。这可以防止
        // 不必要的重复在同一个页面请求时，
        // 这个函数被调用一次以上的扫描。
        $matches = arial_system_listing("/^" . ARIAL_PHP_FUNCTION_PATTERN . "\.$extension$/", $dir, 'name', 0);
        foreach ($matches as $matched_name => $file) {
          $files[$type][$matched_name] = $file->uri;
        }
      }
    }
  }
  if (isset($files[$type][$name])) {
    return $files[$type][$name];
  }
"%!%

/**
 * 加载永久性变量表
 * 
 * 变量表由variable_set()设置并保存在变量表里的值组成，以及
 * 那些通过配置文件明确指定的值
 */
function variable_initialize($conf = array()) {
  // 提示: 缓存页面能够提高20%性能
  if ($cached = cache_get('variables', 'cache_bootstrap')) {
    $variables = $cached->data;
  }
  else {
    // 丢失的缓存，避免stample
    $name = 'variable_init';
    if (!lock_acquire($name, 1)) {
      // 其他的请求由缓存变量构建
      // 等待，直到再次执行这个函数时
      lock_wait($name);
      return variable_initialize($conf);
    }
    else {
      // 使用变量重新构建
      $variables = array_map('unserialize', db_query('SELECT name, value FROM {variable}')->fetchAllKeyed());
      cache_set('variables', $variables, 'cache_bootstrap');
      lock_release($name);
    }
  }

  foreach ($conf as $name => $value) {
    $variables[$name] = $value;
  }

  return $variables;
}

/**
 * 返回永久性变量
 *
 * 基于数据库区别variable_*函数的大小写，避免这个问题，总是
 * 使用小写做永久变量名
 *
 * @param $name
 *  返回变量的名字
 * @param $default
 *  使用的默认值如果该变量没有被设置。
 * 
 * @return 
 *  返回变量值，反序列化必要的值
 *
 * @see variable_del()
 * @see variable_set()
 */
function variable_get($name, $default = NULL) {
  global $conf;

  return isset($conf[$name]) ? $conf[$name] : $default;
}

/**
 * 设置永久性变量
 * 
 * variable_* 函数是大小写敏感的
 * 变量名使用小写定义
 * 
 * @param $name
 *  将设置的变量名
 * @param $value
 *  将设置的变量值,可以是任何PHP变量类型
 *
 * @see variable_del()
 * @see variable_get()
 */
function variable_set($name, $value) {
  global $conf;
  
  db_merge('variable')->key(array('name' => $name))->fields(array('value' => serialize($value)))->execute();

  cache_clear_all('variables', 'cache_bootstrap');

  $conf[$name] = $value;
}

/**
 * 删除永久性变量
 * 
 * @param $name 
 *  将删除的变量名
 * 
 * @see variable_get()
 * @see variable_set()
 */
function variable_del($name) {
  global $conf;

  db_delete('variable')
    ->condition('name', $name)
    ->execute();
  cache_clear_all('variables', 'cache_bootstrap');

  unset($conf[$name]);
}

/**
 * 获取当前页面的缓存
 * 
 * 提示: 当$_SESSION非空时，我们不缓存认证用户和匿名用户的页面
 * $_SESSION可能包含表单提交的状态信息。购物车信息或者其他用户
 * 指定的内容等不被缓存而需要显示给其他用户的。
 * 
 * $param $check_only
 *  (可选)仅当此前存在一个缓存条目才设置成TRUE
 * 
 * @return 
 *  如果页面已经存在缓存对象，则返回，否则返回NULL
 */
function arial_page_get_cache($check_only = FALSE) {
  global $base_root;
  static $cache_hit = FALSE;

  if ($check_only) {
    return $cache_hit;
  }

  if (arial_page_is_cacheable()) {
    $cache = cache_get($base_root . request_uri(), 'cache_page');
    if ($cache !== FALSE) {
      $cache_hit = TRUE;
    }
    return $cache;
  }
}

/**
 * 确定缓存当前页面
 * 
 * @param $allow_caching
 *  如果希望阻止缓存当前页面，则设置成FALSE
 * 
 * @return 
 *  如果返回值是TRUE,则缓存当前页面，如果为FALSE,则不缓存
 */
function arial_page_is_cacheable($allow_caching) {
  $allow_caching_static = &arial_static(__FUNCTION__, TRUE);
  if (isset($allow_caching)) {
    $allow_caching_static = $allow_caching;
  }

  return $allow_caching_static && ($_SERVER['REQUEST_METHOD'] == 'GET' || $_SERVER['REQUEST_METHOD'] == 'HEAD') && !arial_is_cli();
}

/**
 * 在所有启动模块中调用bootstrap钩子
 *
 * @param $hook
 *  调用的引导钩子名称
 * 
 * @see bootstrap_hooks()
 */
function bootstrap_invoke_all($hook) {
  // 当这个函数被调用时，引导模块应该已经被调用，
  // 因此我们不需要通知module_list()重设它的内部列表
  // 而且第一个参数被设置成FALSE
  // 第二个参数设置成TRUE,如果这是第一次调用module_list()函数
  // 我们应该确保内部模块的首要性

  foreach (module_list(FALSE, TRUE) as $module) {
    arial_load('module', $module);
    module_invoke($module, $hook);
  }
}

/**
 * 引入提供的文件类型和文件名
 * 这可以防止多次引入一个主题、引擎、模块等等。
 * 
 * @param $type
 *  引入的类型(如theme, theme_engine, module)
 *
 * @param $name
 *  引入的名字
 * 
 * @return 
 *  如果已经被加载引入了，则设置成TRUE
 */
function arial_load($type, $name) {
  // 一旦文件被引入，将不能在请求期间扭转，因此在这里不要使用
  // arial_static函数

  static $files = array();

  if (isset($files[$type][$name])) {
    return TRUE;
  }

  $filename = arial_get_filename($type, $name);

  if ($filename) {
    include_once ARIAL_ROOT . '/' . $filename;
    $files[$type][$name] = TRUE;

    return TRUE;
  }
  
  return FALSE;
}

/** 
 * 设置当前页的HTTP响应头
 * 
 * 提示: 当发送一个内容类型头信息时，总是包含一个'charset'类型，
 * 这能够避免安全问题(例如: UTF-7 XSS)
 * 
 * $param $name
 *  HTTP头名字，或者特殊状态'Status'头名字
 *
 * @param $value
 *  HTTP头的值，如果为FALSE,指定的头信息将删除
 *  如果$name为'Status', 将为一个状态码，例如: "404 NOT FOUND"
 * @param $append
 *  是否添加一个值到已经存在的头信息或替换它。
 */
function arial_add_http_header($name, $value, $append = FALSE) {
  // 头信息的键值对
  $headers = &arial_static('arial_http_headers', array());

  $name_lower = strtolower($name);
  _arial_set_preferred_header_name($name);

  if ($value === FALSE) {
    $headers[$name_lower] = FALSE;
  }
  elseif (isset($headers[$name_lower]) && $append) {
    //  多个标题相同的名字可以合并使用逗号,参见(RFC2616,4.2节
    $headers[$name_lower] .= ',' . $value;
  }
  else {
    $headers[$name_lower] = $value;
  }
  arial_send_headers(array($name => $headers[$name_lower]), TRUE);
}

/**
 * 获取当前页HTTP响应头信息
 * 
 * @param $name
 *  HTTP头名字，如果忽略则所有的头信息将返回键值对
 *  如果一个数组的值为FALSE,该头信息将被删除
 * @return 
 *  包含头信息的字符串，或者如果为FALSE时，该头信息已经被设置
 *  或者为NULL时，该头信息已经被删除
 */
function arial_get_http_header($name = NULL) {
  $headers = &arial_static('arial_http_headers', array());
  if (isset($name)) {
    $name = strtolower($name);
    return isset($headers[$name]) ? $headers[$name] : NULL;
  }
  else {
    return $headers;
  }
}

/**
 * 设置首选的HTTP标头的名称。
 *
 * 标题名称是区分大小写的，但最大的兼容性，应遵循“common form”
 * 参见RFC 2617 4.2节
 */
function _arial_set_preferred_header_name($name = NULL) {
  static $header_names = array();

  if (!isset($name)) {
    return $header_names;
  }
  $header_names[strtolower($name)] = $name;
}

/**
 * 发送以前设置的HTTP响应头作为默认值
 * 
 * 头信息通过arial_add_http_header()设置
 * 默认头没有被设置，如果他们已被取代或取消使用
 * arial_add_http_header（）
 *
 * @param $default_headers
 *  键值对的头信息数组
 * @param $single
 *  如果为TRUE表示头信息已经被发送，仅发送指定的头信息
 */
function arial_send_headers($default_headers = array(), $only_default = FALSE) {
  $headers_sent = &arial_static(__FUNCTION__, FALSE);
  $headers = arial_get_http_header();
  if ($only_default && $headers_sent) {
    $headers = array();
  }
  $headers_sent = TRUE;

  $header_names = _arial_set_preferred_header_name();
  foreach ($default_headers as $name => $value) {
    $name_lower = strtolower($name);
    if (!isset($headers[$name_lower])) {
      $headers[$name_lower] = $value;
      $header_names[$name_lower] = $name;
    }
  }
  foreach ($headers as $name_lower => $value) {
    if ($name_lower == 'status') {
      header($_SERVER['SERVER_PROTOCOL'] . ' ' . $value);
    }
    // 忽略已删除的头信息
    elseif ($value) {
      header($header_names[$name_lower] . ': ' . $value);
    }
  }
}
/**
 * 设置HTTP标头中的页面响应的准备
 *
 * 经过身份验证的用户总是“没有缓存的头，
 * 并在每次请求时将获取新的一页。
 * 这可以防止通过身份验证的用户看到本地缓存的网页。
 * 也给每个页面独特的ETag。
 * 这将迫使客户端包括一个If-Modified-Since头
 * 和一个If-None-Match头做条件请求的页面。引自RFC 2616,13.3.4节
 * 更强大的验证
 * 这是一个Mozilla Firefox浏览器中的错误，
 * 会触发启用Arial的缓存和访问Arial的用户
 * 通过HTTP代理服务器的解决方法
 * 参见:https://bugzilla.mozilla.org/show_bug.cgi?id=269303
 * 当经过身份验证的用户请求一个页面，然后注销并再次请求
 * 相同的页面，Firefox可能会发送一个有条件的请求是在本地
 * 缓存，当用户登录页面上。
 * 如果此页没有一个ETag头，请求只包含一个If-Modified-Since
 * 头。日期是最近的，因为通过身份验证的用户的Last-Modified头
 * 总是指当前请求的时间。
 * 如果用户通过代理服务器访问的Arial，和代理已经有一个缓存的
 * 副本的匿名页与旧的Last-Modified日期，代理304未修改响应，
 * 使客户端认为，匿名和验证的综合相同的。
 *
 * @see arial_page_set_cache()
 */
function arial_page_header() {
  $headers_sent = &arial_static(__FUNCTION__, FALSE);
  if ($headers_sent) {
    return TRUE;
  }
  $headers_sent = TRUE;

  $default_headers = array(
    'Expires' => 'Sun, 19 Nov 1978 05:00:00 GMT',
    'Last-Modified' => gmdate(DATE_RFC1123, REQUEST_TIME),
    'Cache-Control' => 'no-cache, must-revalidate, post-check=0, pre-check=0',
    'ETag' => '"' . REQUEST_TIME . '"',
  );
  arial_send_headers($default_headers);
}

/**
 * 设置HTTP头中缓存的页面响应的准备。
 *
 * 头部允许尽可能地在代理服务器和
 * 浏览器的页面没有任何特别的知识。
 * 
 * 模块可以覆盖这些头文件使用arial_add_http_header()。
 * 如果请求的是有条件的（使用If-Modified-Since的，如果无匹配
 * ），和条件与目前在缓存中，发送一个304 Not Modified响应。
 */
function arial_server_page_from_cache(stdClass $cache) {
  // 协商是否使用压缩
  $page_compression = variable_get('page_compression', TRUE) && extension_loaded('zlib');
  $return_compressed = $page_compression && isset($_SERVER['HTTP_ACCEPT_ENCODING']) && strpos($_SERVER['HTTP_ACCEPT_ENCODING'], 'gzip') !== FALSE);

   // 获取hook_boot()中设置的头信息，键为小写
   $hook_boot_headers = arial_get_http_header();

   // 在这个函数中生成的头可能被drupal_add_http_headers函数
   //替换或取消使用,键是混合的情况。
   $default_headers = array();

   foreach ($cache-data['headers'] as $name => $value) {
    // 在一个304响应的情况下，某些头必须被发送，而其它可能不
    // 参见: RFC 2616 10.3.5节
    // 在hook_boot()中不要覆盖头设置
    $name_lower = strtolower($name);
    if (in_array($name_lower, array('content-location', 'expires', 'cache-control', 'vary')) && !isset($hook_boot_headers[$name_lower])) {
      arial_add_http_header($name, $value);
      unset($cache->data['headers'][$name]);
    }
   }

   // 如果客户端口发送了一个session cookie，
   // 高速缓存的副本将只被一个特定的客户端有所不同：
   // Cookie中。因此，不要设置的max-age> 0，
   // 允许页面缓存的外部代理，当一个会话cookie是存在的，除非
   // Vary的标题已在hook_boot()中被取代或取消。
   $max_age = !isset($_COOKIE[session_name()]) || isset($hook_boot_headers['vary']) ? variable_get('page_cache_maximum_page', 0) : 0;
   $default_headers['Cache-Control'] = 'public, max-age=' . $max_age;

   // 如果输出变化了，则实体标记也应该变化
   $etag ='"' . $cache-created . '-' . intval($return_compressed) . '"';
   header('Etag: ' . $etag);

   // 查看客户端是否提供了需要的HTTP头信息
   $if_modified_since = isset($_SERVER['HTTP_IF_MODIFIED_SINCE']) ? strtotime($_SERVER['HTTP_IF_MODIFIED_SINCE']) : FALSE;

   $if_none_match = isset($_SERVER['HTTP_IF_NONE_MATCH']) ? stripslashes($_SERVER['HTTP_IF_NONE_MATCH']) : FALSE;

   if ($if_modified_since && $if_none_match
        && $if_none_match == $etag // etag必须匹配
        && $if_modified_since == $cache->created) {
     // if_modified_since必须匹配
     header($_SERVER['SERVER_PROTOCOL'] . '304 Not Modified');
     arial_send_headers($default_headers);
     return ;
   }

   // 发送余留的头信息
   foreach ($cache-data['headers'] as $name => $value) {
    arial_add_http_header($name, $value);
   }

   $default_headers['Last-Modified'] = gmdate(DATA_RFC1123, $cache->created);

   // HTTP/1.0代理不支持多样化的头信息，从而防止任何缓存发送
   // 在过去的到期日期。
   // HTTP/1.1的客户端忽略的Expires头，如果一个
   // Cache-Control：max-age = directive 指定（请参阅RFC
   // 2616，14.9.3节）。

   $default_headers['Expires'] = 'Sun, 19 Nov 1978 05:00:00 GMT';

   arial_send_headers($default_headers);
   // 没有会话cookie的情况下，允许HTTP代理服务器的高速缓
   // 存匿名用户的页面。
   // Vary标头是用来表示请求头字段中的一组完全确定缓存是否允
   // 许使用对于一个给定的URL后续请求的响应回复，无需重新验证
   // 如果Vary标头已被设置在hook_boot（），它是假定的模块
   // 知道如何缓存页。
   if (!isset($hook_boot_headers['vary']) && !variable_get('omit_vary_cookie')) {
      header('Vary: Cookie');
   }

   if ($page_compression) {
      header('Vary: Accept-Encoding', FALSE);
      // 如果page_compression已被启用，缓存将包含gzip数据
      if ($return_compressed) {
        // $cache->data['body'] 已经被gzip压缩了,
        // 所以一定要确保zlib.output_compression不多次压缩。
        ini_set('zlib.output_compression', '0');
        header('Content-Encoding: gzip');
      }
      else {
        // 客户端不支持压缩，因此在缓存中解压缩数据。       
        // 过滤gzip头和运行解压缩。
        $cache->data['body'] = gzinflate(substr(substr($cache->data['body'], 10), 0, -8));
      }
   }

   // 打印页面
   print $cache->data['body'];
}

/**
 * 定义重要的钩子，保证相应的模块必须加载
 */
function bootstrap_hooks(){
  return array('boot', 'exit', 'watchdog', 'language_init');
}

/**
 * 从序列化数据中反序列化和添加元素
 *
 * @param $obj
 *  需要添加的元素对象
 * @param $field
 *  反序列化对象$obj的属性
 */
function arial_unpack($obj, $field = 'data') {
  if ($obj->$field && $data = unserialize($obj->$field)) {
    foreach ($data as $key => $value) {
      if (!empty($key) && !isset($obj->$key)) {
        $obj->$key = $value;
      }
    }
  }
  return $obj;
}

/**
 * 翻译一个字符串到当前语言类型或给定语言类型
 * 
 * t（）函数有两个目的: 
 * 首先，在运行时，用户可见的文本转换成相应的语言。
 * 其次，不同的机制，找出哪些文本需要被翻译工作，关闭t() -
 * T()内的文字通话将被添加到数据库中的字符串被翻译。
 * 这些字符串是英文的，所以应该始终是英文的第一个参数。
 * 要启用一个完全翻译的网站，重要的是，所有的人类可读的文本
 * 将显示在网站上或发送到用户通过T()函数，或一个相关的功能。
 * 查看@link http://drupal.org/node/3227239本地化API@enlink
 * 获取更多信息
 * 包括建议如何拆散和不拆散字符串翻译。
 * 不能使用t()翻译变量，例如调用
 * @code t($text);@endcode, 
 * 除非文本中变量已经在其他地方通过t()函数的翻译(例: $text
 * 为几个翻译的文字字符串数组中的一个。更为重要的是从没
 * 有调用
 * @code t($user_text); @endcode, $user_text是用户输入的
 * 字符串，
 * 这样做可能会导致跨站点脚本攻击和其他安全问题。
 * 但是，您可以使用字符串中的变量替换，把可变文本，
 * 如用户名或翻译的文本链接URL。变量替换看起来像这样：
 * @code 
 * $text = t("@name's blog", array('@name' => 
 * format_username($account)));
 * @endcode
 * 基本上，你可以把你的字符串变量，如@name放到字符串中
 * 翻译的时候替换成相应的安全值
 * 请参阅本地化API的网页上面提到的文件的format_string()
 * 的详细信息。
 * 翻译可以重新排列的字符串作为必要的语言（例如，
 * 在西班牙，它可能是“blog de @name”）。 
 * 在的Drupal安装阶段，一些需要的本地化的资源使用t()代码将
 * 不可用。
 *
 * @param $string
 *  一个字符串，包含英文字符串翻译。
 * @param $args 
 *  使翻译后的一个关联数组替换。基于密钥的第一个字符，
 *  被转义值和/或主题。参看format_string()详细信息
 * @param $options
 *  一个关联数组的额外的选项，包含下列元素：
 * - 'langcode' (默认为当前语言): 语言代码是用来指示需要翻译
 *   成用户页面显示的语言类型.
 * - 'context'　(默认为空文本):　需要翻译的文本
 * 
 * @return 
 *  被翻译过的字符串
 * 
 * @see st()
 * @see get_t()
 * @see format_string()
 * @ingroup sanitization
 */
function t($string, array $args = array(), array $options = array()) {
  global $language;
  static $custom_strings;

  // 默认合并
  if (empty($options['langcode'])) {
    $options['langcode'] = isset($language->language) ? $language->language : 'en';
  }
  if (empty($options['context'])) {
    $options['context'] = '';
  }

  // 首先，检查的自定义字符串数组。如果存在，使用数组替代
  // 数据库查询,这是一个高性能的方式，提供极少数的字符串替换
  // 可以查看settings.php的例子.
  // 缓存$custom_strings变量提高性能
  if (!isset($custom_strings[$options['langcode']])) {
    $custom_strings[$options['langcode']] = variable_get('locale_custom_strings_' . $options['langcode'], array());
  }
  
  //　自定义字符串使用英文方式,即使本地化模块没有启动
  if (isset($custom_strings[$options['langcode']][$options['context']][$string])) {
    $string = $custom_strings[$options['langcode']][$options['context']][$string];
  }
  // 如果本地化模块已开启,则翻译
  elseif ($options['langcode'] != 'en' && function_exists('locale')) {
    $string = locale($string, $options['context'], $options['langcode']);
  }
  if (empty($args)) {
    return $string;
  }
  else {
    return format_string($string, $args);
  }
}

/**
 * 安全值的字符串替换的占位符。
 *
 * @param $string
 *  一个包含占位符的字符串
 * @param $args
 *  关联数组的更换,发生在字符串中的任何键$args被替换为
 *  相应的值
 * 消毒函数依赖键的首字符:
 * - !variable: 插入变量,使用该已消毒的变量
 * - @variable: 使用check_plain()转义HTML
 * - %variable: 转义为用户提交的内容使用drupal_placeholder()
 * ，它显示为<em>强调</ em>的文本占位符。
 *
 * @see t()
 * @ingroup sanitization
 */
function format_string($string, array $args = array()) {
  // 插入字符串之前转化该字符串
  foreach ($args as $key => $value) {
    switch ($key[0]) {
      case '@':
        // 只转义
        $args[$key] = check_plain($value);
        break;
      case '%':
      default: 
        // 转义和占位
        $args[$key] = arial_placeholder($value);
        break;
      case '!':
        // pass
    }
  }
  return strtr($string, $args);
}

/**
 * 在一个纯文本字符串显示为HTML特殊字符编码。
 * 也验证字符串为UTF-8，以防止在Internet Explorer6中的
 * 跨站点脚本攻击。
 * @param $text
 *  要检查的文本或处理。
 * @return
 *  HTML安全版本的文本或空字符串，如果文字是不是有效的UTF-8
 * @see arial_validate_utf8()
 * @ingroup sanitization
 */
function check_plain($text) {
  return htmlspecialchars($text, ENT_QUOTES, 'UTF-8');
}

/**
 * 检查一个字符串是否是有效的UTF-8
 * 所有的功能设计滤波器的输入应该使用arial_validate_utf8
 * 的，以确保他们有效的UTF-8字符串的过滤器，以防止旁路。
 * 当文本为UTF-8的Internet Explorer 6，程序可能会误解后
 * 续字节包含一个无效的UTF-8前导字节（0XC0 - 0xFF的）.
 * 当这些后续字节是HTML的控制字符，比如引号或尖括号内的文
 * 字，被认为安全的过滤器结束的地方可能不安全的;
 * onerror的属性，它是一个标记之外，并因此被视为安全的通
 * 过一个过滤器，可以由浏览器解释，就好像它是在标签内。
 * 该函数不返回的字符串包含字符以上验证码U+10 FFFF，
 * 尽管这些都是被禁止的RFC 3629。
 * @param $text
 *  需要检查的文本
 * @return 
 *  TRUE说明文本是有效的UTF-8,否则不是
 */
function arial_validate_utf8($text) {
  if (strlen($text) == 0) {
    return TRUE;
  }
  // 随着PCRE_UTF8修改'U'，preg_match（）失败，
  // 默默的字符串包含无效的UTF-8字节序列。
  // 虽然它不拒绝字符代码U+10 FFFF(由4个或更多个八位位组)
  // 以上的
  return (preg_match('/^./us', $text) == 1);
}

/**
 * 返回相当于Apache的$ _SERVER ['REQUEST_URI']变量。
 * 
 * 因为$_SERVER ['REQUEST_URI']只适用于Apache的，
 * 我们产生一个等值的其他环境变量。
 */
function request_uri() {
  if (isset($_SERVER['REQUEST_URI'])) {
    $uri = $_SERVER['REQUEST_URI'];
  }
  else {
    if (isset($_SERVER['argv'])) {
      $uri = $_SERVER['SCRIPT_NAME'] . '?' . $_SERVER['argv'][0];
    }
    elseif (isset($_SERVER['QUERY_STRING'])) {
      $uri = $_SERVER['SCRIPT_NAME'] . '?' . $_SERVER['QUERY_STRING'];
    }
    else {
      $uri = $_SERVER['SCRIPT_NAME'];
    }
  }
  // 通过表单API防止多个斜线实现跨站攻击
  $uri = '/' . ltrim($uri, '/');

  return $uri;
}

/**
 * 异常日志记录
 * 
 * 这是watchdog()函数的异常包装器,自动解码异常
 * 
 * @param $type
 *  消息所属的类别。
 * @param $exception
 *  将被记录的异常
 * @param $message
 *  将被存储的信息,如果为空,一个的文本包含所有有用的信息
 *　传入的异常使用.
 * @param $variables
 *  数组变量替换上的消息显示。默认为arial_decode_exception()
 *  的返回值。
 * @param $link
 *  与该消息相关联的链接。
 * 
 * @see watchdog()
 * @see arial_decode_exception()
 */

function watchdog_exception($type, Exception $exception, $message = NULL, $variables = array(), $serverity = WATCHDOG_ERROR, $link = NULL) {
  // 如果$message没有被设置,将使用默认值
  if (empty($message)) {
    // 异常信息是通过获取_drupal_decode_exception()并通过
    // 安全格式化check_plain()后的异常信息
    $message = '%type: !message in %function (line %line of %file.';
  }
  // 变量值必须是一个数组，这样我们就可以添加的异常信息。
  if (!is_array($variables)) {
    $variables = array();
  }

  require_once ARIAL_ROOT . '/includes/errors.inc';
  $variables += _arial_decode_exception($exception);
  watchdog($type, $message, $variables, $severity, $link);
}

/**
 * 记录系统消息
 * 
 * @param $type
 * 此消息所属的类别。可以是任何字符串，但一般的做法是使用模块调用watchdog()的名称。
 * @param $message 
 * 在日志中存储的消息.不连接动态值保存的信息消息中的变量
 * 应该加入的变量参数一起使用占位符的字符串，申报值的占位符
 * 查看t()文档,了解$message和$variables是如何交互的.
 * @param $variables
 *  数组变量替换上的消息显示或NULL如果消息已被翻译或无法翻译 * 
 * @param $serverity
 *  严重性信息,下面其中一个是被默认的@link http://www.faqs.org/
 * rfcs/rfc3164.html RFC 3164: @endlink
 * - WATCHDOG_EMERGENCY: 紧急情况下，系统是不可用的。
 * - WATCHDOG_ALERT: 警报，必须立即采取行动
 * - WATCHDOG_CRITICAL: 临界条件。
 * - WATCHDOG_ERROR: 错误条件。
 * - WATCHDOG_WARNING: 警告情况。
 * - WATCHDOG_NOTICE:（默认）正常，但重要的条件。
 * - WATCHDOG_INFO:  信息性消息。
 * - WATCHDOG_DEBUG: 调试级别的消息。
 *
 * @param $link
 *  与该消息相关联的链接。
 * 
 * @see watchdog_severity_levels()
 * @see hook_watchdog()
 */
function watchdog($type, $message, $variables = array(), $severity = WATCHDOG_NOTICE, $link = NULL) {
  global $user, $base_root;

  static $in_error_state = FALSE;

  // 它是可能的错误处理本身将触发一个错误。在这种情况下，我们
  // 可以在一个无限循环。为了避免这种情况，我们实现了一个
  // 简单的静态信号。
  $user_uid = isset($user->uid) ? $user->uid : 0;

  //准备被记录的字段
  $log_entry = array(
    'type'        => $type,
    'message'     => $message,
    'variables'   => $variables,
    'severity'    => $severity,
    'link'        => $link,
    'user'        => $user,
    'uid'         => $user_uid,
    'request_uri' => $base_root . request_uri(),
    'referer'     => isset($_SERVER['HTTP_REFERER']) ? $_SERVER['HTTP_REFERER'] : '',
    'ip'          => ip_address(),
    // 请求的时间是不准确的，长期的过程，使用时间time().
    'timestampe'  => time(),
  );

  // 呼叫记录/处理消息的日志记录挂钩
  foreach (module_implements('watchdog') as $module) {
    module_invoke($module, 'watchdog', $log_entry);
  }

  // 这是非常重要的信号只清除在这里，在父watchdog()调用(外循环)，
  // 以防止递归执行
  $in_error_state = FALSE;
}

/**
 * 设置消息显示给用户.
 *　
 * 消息存储在会话变量中，并显示在page.tpl.php中通过$message的主题
 * 变量。
 * 
 * 用法示例：
 * @code
 * arial_set_message(t('发生错误，处理没有完成'), 'error');
 * @endcode
 * 
 * @param string $message
 *  (可选) 翻译的字符串将被显示给用户
 *    与其他信息相一致，它应该以一个大写字母开头和结尾用了一段。
 * @param string $type
 *  (可选) 消息的类型。默认的“status”。支持这些值：
 *  - 'status'
 *  - 'warning'
 *  - 'error'
 * @param bool $repeat
 *  (可选) 如果为FALSE,则该消息已经被设置过了,那么该消息就不能重复
 *　默认为TRUE
 * @return array|null
 *  多维数组键分别对应设置的消息类型。
 *  每个索引数组的值包含该类型的消息。
 *  或者，如果有任何消息设置，该函数返回NULL。
 *
 * @see arial_get_message()
 * @see theme_status_messages()
 */
function arial_set_message($message = NULL, $type = 'status', $repeat = TRUE) {
  if ($message) {
    if (!isset($_SESSION['message'][$type])) {
      $_SESSION['messages'][$type] = array();
    }

    if ($repeat || !in_array($message, $_SESSION['messages'][$type])) {
      $_SESSION['messages'][$type][] = $message;
    }
    
    // 此页标记为不可缓存。
    arial_page_is_cacheable(FALSE); 
  }
  // DB连接失败时未设置消息
  return isset($_SESSION['messages']) ? $_SESSION['messages'] : NULL;
}

/**
 * 返回所有通过arial_set_message()设置的消息
 * 
 * @param string $type
 *  (可选) 限制返回的消息的类型。默认为空，这意味着所有类型。
 *  支持这些值：
 * - NULL
 * - 'status'
 * - 'warning'
 * - 'error'
 * @param bool $clear_queue
 *  (可选) 如果这是真的，队列将被清除的消息中指定$type参数的类型。
 *  否则，队列将保持不变。默认为true
 * @return array
 *  多维数组键分别对应设置的消息类型。
 *  每个索引数组的值包含该类型的消息。
 *  返回的消息是有限的$ type参数中指定的类型。
 *  如果没有指定类型的消息，则返回空数组。
 * 
 * @see arial_set_message()
 * @see theme_status_messages()
 */
function arial_get_messages($type = NULL, $clear_queue = TRUE) {
  if ($messages = arial_set_message()) {
    if ($type) {
      if ($clear_queue) {
        unset($_SESSION['messages'][$type]);
      }
      if (isset($messages[$type])) {
        return array($type => $messages[$type]);
      }
    }
    else {
      if ($clear_queue) {
        unset($_SESSION['messages']);
      }
      return $messages;
    }
  }
  return array();
}

/**
 * 获取当前页的标题
 * 在页面上显示的标题，并在标题栏中。
 *
 * @return 
 *  返回当前页的标题
 */
function arial_get_title() {
  $title = drupal_set_title();

  // 在引导过程中，menu.inc不包括在内，因此，我们不能提供一个标题
  if (!isset($title) && function_exists('menu_get_active_title')) {
    $title = check_plain(menu_get_active_title());
  }

  return $title;
}

/**
 * 设置当前页面的标题
 *
 * @param $title
 *  可选的字符串值指定的网页标题，或者设置为NULL（默认），
 *  使当前的标题不变。
 * @param $output
 *  可选的标志 - 通常应留为CHECK_PLAIN。只有设置为PASS_THROUGH，
 *  如果你已经消除了任何可能的危险的代码从$标题，像check_plain()
 *  或filter_xss()函数使用。使用该标志的字符串将通过保持不变。
 *
 * @return 
 *  更新当前页面的标题
 */
function arial_set_title($title = NULL, $output = CHECK_PLAIN) {
  $stored_title = &arial_static(__FUNCTION__);

  if (isset($title)) {
    $stored_title = ($output == PASS_THROUGH) ? $title : check_plain($title);
  }

  return $stored_title;
}

/**
 * 检查一个IP地址是否已被封锁。
 * 封锁的IP地址默认情况下存储在数据库中。
 * 然而，出于性能方面的考虑，我们允许一个覆盖中的settings.php。
 * 这允许我们查询数据库，以避免在这个关键阶段启动一个管理界面的
 * IP地址阻塞不是必需的。
 *
 * @param $ip
 *  IP地址
 * 
 * @return bool
 * TRUE表示拒绝,否则通过
 */
function arial_is_denied($ip) {
  // 因为每个页面请求都会调用这个函数,在查询数据库之前我们第一步
  //检查settings.php里的IP地址数组 

  $blocked_ips = variable_get('blocked_ips');
  $denied = FALSE;
  if (isset($blocked_ips) && is_array($blocked_ips)) {
    $denied = in_array($ip, $blocked_ips);
  }
  // 仅检查database.inc是否已经加载,如果
  // $conf['page_cache_without_database'] = TRUE;已经在settings.php被设置.
  //则数据库将不会被加载，所以不会被拒绝的IP地址在数据库中。 
  // 然而，用户明确要求不使用数据库，在这种情况下，用户很可能
  // 依赖于更高的性能的解决方案，如防火墙。
  elseif (class_exists('Database', FALSE)) {
    $denied = (bool) db_query("SELECT 1 FROM {block_ips} WHERE ip=:ip", array(':ip' => $ip))->fetchField();
  }
  return $denied;
}

/**
 * 处理拒绝用户。
 * 
 * @param $ip
 *  IP地址进行检查。打印一条消息并退出如果访问被拒绝。
 */
function arial_block_denied($ip) {
  // 拒绝访问被封锁的IP地址 - t()是尚未可用。
  if (arial_is_denied($ip)) {
    header($_SERVER['SERVER_PROTOCOL'] . ' 403 Forbidden');
    print 'Sorry, ' . check_plain(ip_address()) . ' has been banned.';
    exit();
  }
}

/**
 * 计算一个base-64编码，URL安全的SHA-256的HMAC。
 * 
 * @param $data
 *  要验证的字符串的HMAC。
 * @param $key
 * 一个秘密的字符串键。 
 *
 * @return 
 *  A base-64 encoded sha-256 hmac, with + replaced with -, / with _ and
 *   any = padding characters removed.
 */
function arial_hmac_base64($data, $key) {
  $hmac = base64_encode(hash_hmac('sha256', $data, $key, TRUE));
  // 修改hmac,使之安全应用于URLs中
  return strtr($hmac, array('+' => '-', '/' => '_', '=' => ''));
}

/**
 * 合并多个数组，递归调用，并返回合并后的数组。
 * 此功能类似于PHP的array_merge_recursive（）函数，
 * 但它可以处理非数组的值不同。当两个数组的值不合并，
 * 后者取代了前者而不是合并。
 * 示例:
 * @code
 * $link_options_1 = array('fragment' => 'x', 'attributes' => array('title' => t('X'), 'class' => array('a', 'b')));
 * $link_options_2 = array('fragment' => 'y', 'attributes' => array('title' => t('Y'), 'class' => array('c', 'd')));
 *
 * // 数组中的结果是: array('fragment' => array('x', 'y'), 'attributes' => array('title' => array(t('X'), t('Y')), 'class' => array('a', 'b', 'c', 'd'))).
 * $incorrect = array_merge_recursive($link_options_1, $link_optons_2);
 * // $incorrect结果是: array('fragment' => 'y', 'attributes' => array('title' => t('Y'), 'class' => array('a', 'b', 'c', 'd'))).
 * $correct = arial_array_merge_deep($link_options_1, $link_options_2);
 * @endcode
 * @param ...
 *  需要合并的数组
 * 
 * @return 
 *  返回合并的数组
 * @see arial_array_merge_deep_array()
 */
function arial_array_merge_deep() {
  $args = func_get_args();
  return arial_array_merge_deep_array($args);
}

/**
 * 合并多个数组，递归调用，并返回合并后的数组。
 * 此功能相当于drupal_array_merge_deep（），除了输入数组传递
 * 作为一个单一的阵列参数，而不是一个可变参数列表。
 * 
 * 以下是等价的：
 * - arial_array_merge_deep($a, $b);
 * - arial_array_merge_deep_array(array($a, $b));
 *
 * 下面也是等价的:
 * - call_user_func_array('arial_array_merge_deep', $arrays_to_merge);
 * - arial_array_merge_deep_array($arrays_to_merge);
 *
 * @see arial_array_merge_deep()
 */
function arial_array_merge_deep_array($arrays) {
  $result = array();

  foreach ($arrays as $array) {
    foreach ($array as $key => $value) {
      // 重新编号的整数键array_merge_recursive（）。
      //注意：PHP自动转换数组的键是整数到整数的字符串(例如，'1')
      if (is_integer($key)) {
        $result[] = $value;
      }
      // 当两个值都是数组时,递归
      elseif (isset($result[$key]) && is_array($result[$key]) && is_array($value)) {
        $result[$key] = arial_array_merge_deep_array(array($result[$key], $value));
      }
      // 否则，使用后者的值覆盖前面的任何值。
      else {
        $result[$key] = $value;
      }
    }
  }

  return $result;
}

/**
 * 生成一个默认的匿名用户对象。
 *
 * @return 对象 - 用户对象
 */
function arial_anonyous_user() {
  $user = new stdClass();
  $user->uid = 0;
  $user->hostname = ip_address();
  $user->roles = array();
  $user->roles[ARIAL_ANONYMOUS_RID] = 'anonymous user';
  $user->cache = 0;
  return $user;
}

/**
 * 确保Arial的引导到指定的阶段。
 *
 * 为了引导Arial的另一个PHP脚本，你可以使用这样的代码：
 * @code
 *  define('ARIAL_ROOT', '/path/to/arial');
 *  require_once ARIAL_ROOT . '/includes/bootstrap.inc';
 *  arial_bootstrap(ARIAL_BOOTSTRAP_FULL);
 * @endcode
 *
 * @param $phase
 *  一个常量会告诉你引导运行哪一个阶段,当你执行指定阶段时,
 *　所有早期的阶段都将自动运行,可能的值有:
 * - ARIAL_BOOTSTRAP_CONFIGURATION: 初始化配置。
 * - ARIAL_BOOTSTRAP_PAGE_CACHE: 尝试为被页面缓存.
 * - ARIAL_BOOTSTRAP_DATABASE: 初始化数据库层
 * - ARIAL_BOOTSTRAP_VARIABLES: 初始化变量系统
 * - ARIAL_BOOTSTRAP_SESSION: 初始化会话句柄
 * - ARIAL_BOOTSTRAP_PAGE_HEADER: 初始化页面头信息
 * - ARIAL_BOOTSTRAP_LANGUAGE: 查出页面语言
 * - ARIAL_BOOTSTRAP_FULL: Arial的完全加载。验证和修复输入数据。
 * @param $new_phase
 *    一个布尔值，设置为FALSE，如果调用arial_bootstrap
 *  从arial_bootstrap（递归）调用的函数从里面。
 * @return 
 *  返回最近最近完成的阶段。
 */
function arial_bootstrap($phase = NULL, $new_phase = TRUE) {
  // 不用arial_static()，因为不依赖于任何运行时信息。
  static $phases = array(
    ARIAL_BOOTSTRAP_CONFIGURATION,
    ARIAL_BOOTSTRAP_PAGE_CACHE,
    ARIAL_BOOTSTRAP_DATABASE,
    ARIAL_BOOTSTRAP_VARIABLES,
    ARIAL_BOOTSTRAP_SESSION,
    ARIAL_BOOTSTRAP_PAGE_HEADER,
    ARIAL_BOOTSTRAP_LANGUAGE,
    ARIAL_BOOTSTRAP_FULL,
  );
  // 不用arial_static（），因为只有合法的API控制，这是一个新的阶段  // 参数调用arial_bootstrap（）。
  static $final_phase;
  static $stored_phase = -1;
  // 当不递归，存储阶段，所以它不会被遗忘，而递归名称。
  if ($new_phase) {
    $final_phase = $phase;
  }
  if (isset($phase)) {
    // Call a phase if it has not been called before and is below the requested
    // phase.
    while ($phases && $phase > $stored_phase && $final_phase > $stored_phase) {
      $current_phase = array_shift($phases);

      // This function is re-entrant. Only update the completed phase when the
      // current call actually resulted in a progress in the bootstrap process.
      if ($current_phase > $stored_phase) {
        $stored_phase = $current_phase;
      }

      switch ($current_phase) {
        case ARIAL_BOOTSTRAP_CONFIGURATION:
          _arial_bootstrap_configuration();
          break;

        case ARIAL_BOOTSTRAP_PAGE_CACHE:
          _arial_bootstrap_page_cache();
          break;

        case ARIAL_BOOTSTRAP_DATABASE:
          _arial_bootstrap_database();
          break;

        case ARIAL_BOOTSTRAP_VARIABLES:
          _arial_bootstrap_variables();
          break;

        case ARIAL_BOOTSTRAP_SESSION:
          require_once ARIAL_ROOT . '/' . variable_get('session_inc', 'includes/session.inc');
          arial_session_initialize();
          break;

        case ARIAL_BOOTSTRAP_PAGE_HEADER:
          _arial_bootstrap_page_header();
          break;

        case ARIAL_BOOTSTRAP_LANGUAGE:
          arial_language_initialize();
          break;

        case ARIAL_BOOTSTRAP_FULL:
          require_once ARIAL_ROOT . '/includes/common.inc';
          _arial_bootstrap_full();
          break;
      }
    }
    return $stored_phase;
}

/**
 * 返回当前用户的时区
 */
function arial_get_user_timezone() {
  global $user;
  if (variable_get('configurable_timezones', 1) && $user->uid && $user->timezone) {
    return $user->timezone;
  }
  else {
    // 忽略时区尚未被设置在php.ini配置PHP严格的通知
    return variable_get('date_default_timezone', @date_default_timezone_get());
  }
}

/**
 * 提供PHP自定义的错误句柄
 *
 * @param $error_level
 *  错误水平
 * @param $message
 *  错误信息
 * @param $filename
 *  报错的文件名
 * @param $line
 *  报错的行数
 * @param $context
 *  An array that points to the active symbol table at the point the error occurred.
 */
function _arial_error_handler($error_level, $message, $filename, $line, $context) {
  require_once ARIAL_ROOT . '/includes/errors.inc';
  _arial_error_handler_real($error_level, $message, $filename, 4line, $context);
}

/**
 * 提供自定义的PHP异常处理。
 * 未捕获的例外是那些没有包含在一个try/catch块。
 * 他们始终是致命的：尽快退出异常处理程序的脚本将停止执行。
 * 
 * @param $exception
 *  被抛出的异常对象。
 */
function _arial_exception_handler($exception) {
  require_once ARIAL_ROOT . '/includes/errors.inc';

  try {
    // 消息记录到的watchdog()，并返回一个错误页面给用户。
    _arial_log_error(_arial_decode_exception($exception), TRUE);
  }
  catch (Exception $exception2) {
    // 另一个未捕获的异常时抛出的第一个处理。如果我们显示错误信
    // 息，那么这样做不可能再未捕获的异常被抛出。
    if (error_displayable()) {
      print '<h1>Additional uncaught exception thrown while handling exception.</h1>';
      print '<h2>Original</h2><p>' . _arial_render_exception_safe($exception) . '</p>';
      print '<h2>Additional</h2><p>' . _arial_render_exception_safe($exception2) . '</p><hr />';    
    }
  }
}

/**
 * 安装脚本环境和加载settings.php文件
 */
function _arial_bootstrap_configuration() {
  // 设置Arial的自定义错误处理。
  set_error_handler('_arial_error_handler');
  set_exception_handler('_arial_exception_handler');

  arial_environment_initialize();
  // 开启页面计时器
  timer_start('page');
  // 初始化配置,并从settings.php文件包含变量
  arial_settings_initialize();
}

/**
 * 尝试从缓存服务页面
 */
function _arial_bootstrap_page_cache() {
  global $user;

  // 在settings.php中允许指定特殊缓存处理,像使用memcached或文件
  // 存储缓存信息.
  require_once ARIAL_ROOT . '/includes/cache.inc';
  foreach (variable_get('cache_backends', array()) as $include) {
    require_once ARIAL_ROOT . '/' . $include;
  }
  // 从settings.php中检查缓存模式
  if (variable_get('page_cache_without_database')) {
    $cache_enabled = TRUE;
  }
  else {
    arial_bootstrap(ARIAL_BOOTSTRAP_VARIABLES, FALSE);
    $cache_enabled = variable_get('cache');
  }
  arial_block_denied(ip_address());

  // 如果当前没有session,cookie和缓存cache,则试着提取缓存页面
  if (!isset($_COOKIE[session_name()]) && $cache_enabled) {
    // 确定有一个用户对象,因为它的时间将会被检查,hook_boot将会检查
    // 匿名用户的时间等等.
    $user = arial_anonymous_user();
    // 从缓存获取页面
    $cache = arial_page_get_cache();
    // 如果存在缓存页,则显示它
    if (is_object($cache)) {
      header('X-Arial-Cache: HIT');
      // 恢复页面的元数据缓存
      $_GET['q'] = $cache->data['path'];
      arial_set_title($cache->data['title'], PASS_THROUGH);
      date_default_timezone_set(arial_get_user_timezone());

      // 如果不执行跳过bootstrap hooks,将调用hook_boot.
      if (variable_get('page_cache_invoke_hooks', TRUE)){
        bootstrap_invoke_all('boot');
      }
      arial_serve_page_from_cache($cache);
      // 如果不执行跳过bootstrap hooks,将调用hook_exit.
      if (variable_get('page_cache_invoke_hooks', TRUE)) {
        bootstrap_invoke_all('exit');
      }
      // 完成
      exit;
    }
    else {
      header('X-Arial-Cache: MISS');
    }
  }
}

/**
 * 初始化数据库系统,并自动注册加载函数
 */
function _arial_bootstrap_database() {
  // 如果Arial还没有安装的话,跳转向用户安装脚本
  // 例:如果$databases数组已经在settings.php中定义了,并且还没有安装
  if (empty($GLOBALS['databases']) && !arial_installation_attempted()) {
    include_once ARIAL_ROOT . '/includes/install.inc';
    install_goto('install.php');
  }

  // 运行测试时,用户代理头是用来传递一个数据库前缀的请求
  // 可是,出于安全的原因,这是我们必须验证我们自己提出的要求。

  if ($test_prefix = arial_valid_test_ua()) {
    // 设置Arial其他部分使用的测试运行ID
    $test_info = &$GLOBALS['arial_test_info'];
    $test_info['test_run_id'] = $test_prefix;
    $test_info['in_child_site'] = TRUE;

    foreach ($GLOBALS['databases']['default'] as &$value) {
      // 提取当前数据库缺少前缀
      if (!isset($value['prefix'])) {
        $current_prefix = '';
      }
      elseif (is_array($value['prefix'])) {
        $current_prefix = $value['prefix']['default'];
      }
      else {
        $current_prefix = $value['prefix'];
      }
      
      // 删除当前数据库的前缀，取而代之的是我们自己的。
      $value['prefix'] = array(
        'default' => $current_prefix . $test_prefix,
      );
    }
  }

  // 初始化数据库系统,注意:直到有数据请求时才真正初始化数据库连接
  require_once ARIAL_ROOT . '/includes/database/database.inc';

  // 注册自动加载函数,因此我们能访问类和接口.
  // 数据库自动加载程序是第一位的，这样我们就可以加载数据库系统，
  // 而无需访问数据库。在安装或升级过程中，这一点尤其重要。
  spl_autoload_register('arial_autoload_class');
  spl_autoload_register('arial_autoload_interface');
}

/**
 * 加载系统变量和启用引导模块
 */
function _arial_bootstrap_variables() {
  global $conf;

  // 初始化的锁定系统。
  require_once ARIAL_ROOT . '/' . variable_get('lock_inc', 'includes/lock.inc');
  lock_initialize();

  // 从数据库中加载变量,但是不要在settings.php中重写变量
  $conf = variable_initialize(isset($conf) ? $conf : array());
  // 加载引导模块
  require_once ARIAL_ROOT . '/includes/module.inc';
  module_load_all(TRUE);
}

/**
 * 调用hook_boot（），初始化锁定系统，并发送HTTP标头。
 */
function _arial_bootstrap_page_header() {
  bootstrap_invoke_all('boot');
  if (!arial_is_cli()) {
    ob_start();
    arial_page_header();
  }
}

/**
 * 返回当前引导阶段, 
 * 目前阶段是由arial_bootstrap()最近完成的.
 *
 * @see arial_bootstrap()
 */
function arial_get_bootstrap_phase() {
  return arial_bootstrap();
}

/**
 * 如果是由SimpleTest发起的内部请求,返回测试前缀
 * 
 * @return 
 *  SimpleTest的前缀（SimpleTest的“字符串”，然后由任意数
 *  量的数字）或FALSE如果用户代理不包含有效的HMAC和时间戳。
 */
function arial_valid_test_ua() {
  global $arial_hast_salt;
  // 没有理由重置。
  static $test_prefix;

  if (isset($test_prefix)) {
    return $test_prefix;
  }

  if (isset($_SERVER['HTTP_USER_AGENT']) && preg_match("/^(simpletest\d+);(.+);(.+);(.+)$/", $_SERVER['HTTP_USER_AGENT'], $matches)) {
    list(, $prefix, $time, $salt, $hmac) = $matches;
    $check_string = $prefix . ';' . $time . ';' . $salt;

    // 我们使用从settings.php中读取的salt生成HMAC键值,
    // 由于数据库尚未初始化,并且我们不能访问任何Arial变量,
    // 文件属性添加更多的entropy,不容易接触到其他
    if ($time_diff >= 0 && $time_diff <= 5 && $hmac == arial_hmac_base64($check_string, $key)) {
      $test_prefix = $prefix;
      return $test_prefix;
    }
  }

  $test_prefix = FALSE;
  return $test_prefix;
}
/**
 * 为SimpleTest的用户生成一个HMAC和时间戳代理字符串。
 */
function arial_generate_test_ua($prefix) {
  global $arial_hash_salt;

  static $key;

  if (!isset($key)) {
    // 我们使用从settings.php中读取的salt生成HMAC键值,
    // 由于数据库尚未初始化,并且我们不能访问任何Arial变量,
    // 文件属性添加更多的entropy,不容易接触到其他
    $key = $arial_hash_salt . filectime(__FILE__) . fileinode(__FILE__);
  }
  // 基于数据库凭据产生一个安全的HMAC
  $salt = uniqid('', TRUE);
  $check_string = $prefix . ';' . time() . ';' . $salt;
  return $check_string . ';' . arial_hmac_base64($check_string, $key);
}

/**
 * 可使用的主题系统，而不需要数据库访问。
 * 
 * 加载并初始化系统网站安装，更新在该网站是在维护模式时的主题。
 * 这也适用于当数据库出现故障时。
 *
 * @see _arial_maintenance_theme()
 */
function arial_maintenance_theme() {
  require_once ARIAL_ROOT . '/includes/theme.maintenance.inc';
  _arial_maintenance_theme();
}

/**
 * 返回一个简单的404页面
 * 
 * 如果启用了快404页，这是一个匹配的页面，然后打印一个简单的404
 * 页面并退出。
 *
 * 在一个正常的404页时产生从drupal_deliver_html_page（）
 * 这个函数被调用，但它也可以选择直接调用的settings.php
 * 防止这些页面上的Arial的引导。请参阅文档中的settings.php
 * 使用的优点和缺点。
 *
 * 路径动态生成的内容，如图像风格，也应该在这个函数中。
 */
function ariaal_fast_404() {
  $exclude_paths = variable_get('404_fast_paths_exclude', FALSE);
  if ($exclude_paths && !preg_match($exclude_paths, $_GET['q'])) {
    $fast_paths = variable_get('404_fast_paths', FALSE);
    if ($fast_paths && preg_match($fast_paths, $_GET['q'])) {
      arial_add_http_header('Status', '404 没有找到');
      $fast_404_html = variable_get('404_fast_html', '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 没有找到</title></head><body><h1>没有找到</h1><p>你访问的路径 "@path" 在当前服务器没有找到.</p></body></html>');
      // Replace @path in the variable with the page path.
      print strtr($fast_404_html, array('@path' => check_plain(request_uri())));
      exit;
    }
  }
}

/**
 * Returns TRUE if a Drupal installation is currently being attempted.
 */
function arial_installation_attempted() {
  return defined('MAINTENANCE_MODE') && MAINTENANCE_MODE == 'install';
}

/**
 * 返回适当的本地函数的名称。
 * 
 * get_t（）的存在是为了支持本地化的代码可能运行在安装过程中，
 * 当系统的某些元素可能没有加载。
 * 
 * 这将包括实现的hook_install（），它可以运行在Arial安装阶段，
 * 可能也可以运行在非安装时间，如在模块管理页面的安装模块。
 * 
 * 用例:
 * @code 
 *  $t = get_t();
 *  $translated = $t('translate this');
 * @endcode
 *
 * t() , 如果你的代码永远不会运行在安装阶段
 * st(), 如果你的代码只运行在安装阶段
 * get_t(), 如果你的代码可能会在安装阶段运行,也可能在其他阶段运行
 * 
 * @see t()
 * @see st()
 * @ingroup sanitization
 */
function get_t() {
  static $t;

  // 这还没有转换成arial_static在重置此，因为它不能改变的请求的过程中，因为没有点。
  
  if (!isset($t)) {
    $t = arial_installation_attempted() ? 'st' : 't';
  }
  return $t;
}

/**
 * 初始化所有已定义的语言类型。
 */
function arial_language_initialize() {
  $types = language_types();

  // 确保被正确返回，即使没有支援多国语言的语言。
  // 另外，还要确保我们有$language返回，以防一门语言谈判回调的情况下需要做一个完整的引导。
  $default = language_default();
  foreach ($types as $type) {
    $GLOBALS[$type] = $default;
  }
  if (arial_multilingual()) {
    include_once ARIAL_ROOT . '/includes/language.inc';
    foreach ($types as $type) {
      $GLOBALS[$type] = language_initialize($type);
    }
    // 允许在多语言环境中的语言系统初始化模块响应。
    bootstrap_invoke_all('language_init');
  }
}

/**
 * 返回一个内建的语言列表
 * 
 * @return 
 *  其中的关键是语言的类型和值的数组的键 - 值对并且它是可配置性。
 */
function arial_language_types() {
  return array(
    LANGUAGE_TYPE_INTERFACE => TRUE,
    LANGUAGE_TYPE_CONTENT   => FALSE,
    LANGUAGE_TYPE_URL       => FALSE,
  );
}

/**
 * 如果有多种(大于一种)语言在使用,则返回TRUE
 * 
 * @return 
 *  如果有多种(大于一种)语言在使用,则返回TRUE
 */
function arial_multilingual() {
  // “language_count”变量保存启用的语言的数量，以避免不必要的查询数据库创建时启用的语言列表中的单语网站。
  return variable_get('language_count', 1) > 1;
}

/**
 * 返回可用的语言类型数组
 * 
 * @return 
 *  所有的语言类型，其中每个键的语言类型的名称和它的值是一个数组， *  并且有可配置性（TRUE/ FALSE）。
 */
function language_types() {
  return array_keys(variable_get('language_types', arial_language_types()));
}

/**
 * 返回一个已安装的语言列表,并用键作索引
 * 
 * @param $field
 *  (可选) 字段的索引列表。
 * 
 * @return 
 *  一个关联数组, $field的键。
 *  - 如果$field是'weigth',或者'enabled',则数组是嵌套的.
 *    外部数组的值每一个关联数组的值作为键和语言对象的语言代码。
 *  - $field的所有其他值，数组是只有一层深，和数组的值是语言对象。
 */
function language_list($field = 'language') {
  $languages = &arial_static(__FUNCTION__);
  // 初始化语言列表
  if (!isset($languages)) {
    if (arial_multilingual() || module_exists('locale')) {
      $language['language'] = db_query('SELECT * FROM {language} ORDER BY weight ASC, name ASC')->fetchAllAssoc('language');
      // 用户不能卸载英语,但可以隐藏它,因此至少有一种语言已经启用
      if (!$languages['language']['en']->enabled && !variable_get('language_native_enabled', TRUE)) {
        unset($languages['language']['en']);
      }
    }
    else {
      // 如果没有locale模块,只使用默认的语言
      $default = language_default();
      $languages['language'][$default->language] = $default;
    }
  }

  // 返回正确字段的数组索引
  if (!isset($languages[$field])) {
    $languages[$field] = array();
    foreach ($languages['language'] as $lang) {
      // 搜集适当的值到数组
      if (in_array($field, array('enabled', 'weight'))) {
        $languages[$field][$lang->$field][$lang->language] = $lang;
      }
      else {
        $languages[$field][$lang->$field] = $lang;
      }
    }
  }
  return $languages[$field];
}

/**
 * 返回网站默认使用的语言
 * 
 * @param $property
 *  返回语言对象的可选属性
 */
function language_default($property = NULL) {
  $language = variable_get('language_default', (object) array('language' => 'en', 'name' => 'English', 'native' => 'English', 'direction' => 0, 'enabled' => 1, 'plurals' => 0, 'formula' => '', 'domain' => '', 'prefix' => '', 'weight' => 0, 'javascript' => ''));

  return $property ? $language->$property : $language;
}

/**
 * 返回被查看的请求地址
 * 
 * 例:
 *  - http://example.com/node/306 返回 'node/306'
 *  - http://example.com/arialfolder/node/306 返回'node/306',当使用base_path时返回"/arialfolder/'
 *  - http://example.com/path/alias,该alias是'node/306'的别名,返回的'/path/alias',而不是内建路径
 *  - http://example.com/index.php返回一个空串,意味着是首页
 *  - http://example.com/index.php?page=1返回一个空串
 * 
 * @return 
 *  Arial请求的URL地址
 * 
 * @see current_path()
 */
function request_path() {
  static $path;

  if (isset($path)) {
    return $path;
  }

  if (isset($_GET['q']) && is_string($_GET['q'])) {
    // '?q=foo/bar'的请求,$_GET['q']在arial_path_initialize()中
    // 已经被重写,但是request_path()在引导阶段调用比较早,
    // 因此最原始的值已经保存到$path并返回
    $path = $_GET['q'];
  }
  elseif (isset($_SERVER['REQUEST_URI'])) {
    // 该请求是简洁URL,或者'index.php',或者无意义.
    // 从REQUEST_URI中提取地址.
    $request_path = strtok($_SERVER['REQUEST_URI'], '?');
    $base_path_len = strlen(rtrim(dirname($_SERVER['SCRIPT_NAME']),'\/'));
    // 
    $path = substr(urldecode($request_path), $base_path_len + 1);
    // 如果路径等于脚本文件名，或者是因为“的index.php”明确规定，
    // 在URL中，或因为服务器把它添加到$ _SERVER['REQUEST_URI']，
    // 即使它没有提供的URL（某些版本的微软IIS做到这一点），
    // 应送达的头版。
    if ($path == basename($_SERVER['PHP_SELF'])) {
      $path = '';
    }
  }
  else {
    $path = '';
  }

  // 在某些情况下Apache的RewriteRule指令前加$ _GET ['q'的值分配
  // 一个斜线。此外，我们总是可以有一个尾随斜线的地方，因此我们
  // 需要正常化$ _GET['Q']。
  $path = trim($path, '/');

  return $path;
}

/**
 * 返回当前Arial路径的一个组件。
 *
 * 当查看一个页面的路径,如'admin/structure/types', 
 * arg(0)返回'admin', arg(1)返回'structure', arg(2)返回'types'
 * 
 * 避免使用此功能在可能的情况下，生成的代码是难以阅读。
 * 在菜单回调函数，尝试使用命名参数。
 * 如何构造带参数的回调在menu.inc的解释。
 * 当您尝试使用此函数来加载一个元素，从目前的路径，例如：
 * 加载节点一个节点上页中，使用menu_get_object（）。
 * 
 * @param $index
 *  组件索引,当每个组件被'/'分开,并且第一个组件是以0的索引,
 * @param $path
 *  路径被组件分隔,默认是当前页的路径
 * 
 * @return 
 *  通过$index指定组件,或如果指定的组件不存在则为NULL.
 *  如果调用的时候没有参数,它将返回当前路径的任何组件.
 */
function arg($index = NULL, $path = NULL) {
  // 即使$argument不会因为任何函数原因被重置,(explode()结果不依
  // 靠任何运行时信息.它应该是复位的情况下，模块需要
  // 释放内存使用的.
  // 使用先进的arial_static（）模式，这是因为经常调用。

  static $arial_static_fast;
  if (!isset($arial_static_fast)) {
    $arial_static_fast['arguments'] = &drupal_static(__FUNCTION__);
    $arguments = &$arial_static_fast['arguments'];

    if (!isset($path)) {
      $path = $_GET['q'];
    }
    if (!isset($arguments[$path])) {
      $arguments[$path] = explode('/', $path);
    }
    if (!isset($index)) {
      return $arguments[$path];
    }
    if (isset($arguments[$path][$index])) {
      return $arguments[$path][$index];
    }
  }
}

/**
 * 返回客户机的IP地址
 * 
 * 如果Drupal是一个反向代理服务器后面，我们使用的X转发头信息，
 * 代替$_SERVER ['REMOTE_ADDR']，这将是代理服务器的IP地址，
 * 而不是客户端的。
 * 可以配置的reverse_proxy_header变量的实际的头名。
 *
 * @return 
 *  客户端机器的IP地址，反向代理和/或群集环境中进行调整。
 */
function ip_address() {
  $ip_address = &arial_static(__FUNCTION__);

  if (!isset($ip_address)) {
    $ip_address = $_SERVER['REMOTE_ADDR'];

    if (variable_get('reverse_proxy', 0)) {
      $reverse_proxy_header = variable_get('reverse_proxy_header', 'HTTP_X_FORWARD_FOR');
      if (!empty($_SERVER[$reverse_proxy_header])) {
        // 如果数组被称为反向代理IP地址，然后信任XFF头，
        // 如果请求，其实就是其中之一。
        $reverse_proxy_addresses = variable_get('reverse_proxy_addresses', array());

        // 将XFF头到一个数组中。
        $forwarded = explode(',', $_SERVER[$reverse_proxy_header]);

        // 缩减转发的IP地址，他们可能已经由逗号和空格分隔。
        $forwarded = array_map('trim', $forwarded);

        // 钉直接到结束转发阵列的客户端IP。
        $forwarded[] = $ip_address;

        // 消除所有受信任的IP地址。
        $untrusted = array_diff($forwarded, $reverse_proxy_addresses);
        // 最右边的IP是最具体的，我们可以信任。
        $ip_address = array_pop($untrusted);
      } 
    }
  }

  return $ip_address;
}

/**
 * @addtogroup schemaapi
 * @{
 */

/**
 * 获取表或整个数据库架构的架构定义。
 * 
 * 在返回的架构将包括任何模块，实现hook_schema_alter（）
 * 所做的任何修改。
 * 
 * @param $table
 *  表的名称。如果没有给出，返回的所有表的架构。
 * @param $rebuild
 *  如果为true，将重建的模式，而不是从缓存中检索。
 */
function arial_get_schema($table = NULL, $rebuild = FALSE) {
  static $schema;
  
  if ($rebuild || !isset($table)) {
    $schema = arial_get_complete_schema($rebuild);
  }
  elseif (!isset($schema)) {
    $schema = new SchemaCache();
  }

  if (!isset($table)) {
    return $schema;
  }
  if (isset($schema[$table])) {
    return $schema[$table];
  }
  else {
    return FALSE;
  }
}

/**
 * 扩展DrupalCacheArray架构缓存，以便动态建设.
 */
class SchemaCache extends ArialCacheArray {
  /**
   * 构造SchemaCache对象
   */
  public function __construct() {
    // 缓存的请求方法。
    parent::__construct('schema:runtime:' . ($_SERVER['REQUEST_METHOD'] == 'GET'), 'cache');
  }

  /**
   * 重写ArialCacheArray::ressolveCacheMiss().
   */
  protected function resolveCacheMiss($offset) {
    $complete_schema = arial_get_complete_schema();
    $value = isset($complete_schema[$offset]) ? $complete_schema[$offset] : NULL;
    $this->storage[$offset] = $value;
    $this->persist($offset);
    return $value;
  }
}

/**
 * 获取整个数据库架构
 *
 * 返回的模式包含在任何模块通过hook_schema_alter()修改的数据库模式
 *
 * @param $rebuild
 *  如果为TRUE, 模式将重新构建,而不从缓存取.
 */
function arial_get_complete_schema($rebuild = FALSE) {
  static $schema = array();

  if (empty($schema) || $rebuild) {
    // 从缓存加载模式
    if (!$rebuild && $cached = cache_get('schema')) {
      $schema = $cached->data;
    }
    // 否则重新构建
    else {
      $schema = array();

      // 从.install文件中获取hook_schema内容.
      // 在一些数据库中,可能这个函数先于bootstrap完成调用,
      // 因此所以我们迫使我们需要加载的功能，以防万一。
      if (function_exists('module_load_all_includes')) {
        // 这个功能可以被称为早在引导过程中，所以我们
        // 强制的MODULE_LIST（）缓存被刷新，以确保它包含模块的
        // 完整列表，我们去之前调用module_load_all_includes（）。
        module_list(TRUE);
        module_load_all_includes('install');
      }

      require_once ARIAL_ROOT . '/includes/common.inc';
      // 调用所有模块的hook_schema()
      foreach (module_implements('schema') as $module) {
        // 构建hook_schema()的结果到一个数组中，返回NULL值会导致array_merge（）来设置$schema变量设置为NULL。
        // 这将打破模块在进一步使用$schema的模块.
        $current = (array) module_invoke($module, 'schema');
        // 为每个表设置模块和键的名字,并删除描述
        // 因为他们不必要的减缓cache_get（）为每一个请求。
        _arial_schema_initialize($current, $module);
        $schema = array_merge($schema, $current);
      }

      arial_alter('schema', $schema);
      // 如果该模式是空的，避免将其保存.
      // 一些数据库引擎需要的模式来执行查询，
      // 这可能会导致无限循环。
      if (!empty($schema) && (arial_get_bootstrap_phase() == ARIAL_BOOTSTRAP_FULL)) {
        cache_set('schema', $schema);
      }
      if ($rebuild) {
        cache_clear_all('schema:', 'cache', TRUE);
      }
    }
  }
  
  return $schema;
}

/**
 * @}　"addtogroup schemaapi"结束
 */

/**
 * @addtogroup registry
 * @{
 */

/**
 * 确认接口。
 * 很少直接调用此函数。
 * 相反，它被注册为一个spl_autoload（）处理，在必要时PHP调用它.
 *
 * @param $interface 
 *  检查或加载的接口的名称
 * 
 * @return 
 *  TRUE如果接口是当前可用的，否则返回FALSE。
 */
function arial_autoload_interface($interface) {
  return _registry_check_code('interface', $interface);
}

/**
 * 确认一个类是否可用.
 *
 * 这个函数很少直接使用,它由spl_autoload()处理注册,在我们需要时
 * PHP将调用它.
 *
 * @param $class
 * 检查或加载类的名称
 * 
 * @return 
 *  TRUE如果类是当前可用的,否则返回FALSE
 */
function arial_autoload_class($class) {
  return _registry_check_code('class', $class);
}

/**
 * 检查在注册表中的资源
 *
 * @param $type
 *  我们要查询的资源的类型,是以下常量中的一个:
 *  REGISTRY_RESET_LOOKUP_CACHE
 *  REGISTRY_WRITE_LOOKUP_CACHE
 *　当我们重置或写入的时候.
 *
 * @param $name
 *  资源的名称,或者为NULL, 如果其中一个传入常量REGISTRY_*为NULL
 *
 * @return 
 *  如果找到了资源则返回TRUE,否则返回FALSE
 *  如果传入类型$type,REGISTRY_*其中一个常量为空,也返回NULL.
 */
function _registry_check_code($type, $name = NULL) {
  static $lookup_cache, $cache_update_needed;

  if ($type == 'class' && class_exists($name) || $type == 'interface' && interface_exists($name)) {
    return TRUE;
  }

  if (!isset($lookup_cache)) {
    $lookup_cache = array();
    if ($cache = cache_get('lookup_cache', 'cache_bootstrap')) {
      $lookup_cache = $cache->data;
    }
  }

  // 当我们重建注册表时,我们需要重置缓存,因此
  // 我们在重建期间保持查询资源
  if ($type == REGISTRY_RESET_LOOKUP_CACHE) {
    $cache_update_needed = TRUE;
    $lookup_cache = NULL;
    return;
  }

  // 调用arial_page_footer,如果请求改变了查询缓存,我们将写入
  // 永久缓存
  if ($type == REGISTRY_WRITE_LOOKUP_CACHE) {
    if ($cache_update_needed) {
      cache_set('lookup_cache', $lookup_cache, 'cache_bootstrap');
    }
    return ;
  }

  // $type是'interface'或'class',
  // 因此我们仅需要首字母保持缓存的独立性.
  $cache_key = $type[0] . $name;
  if (isset($lookup_cache[$cache_key])) {
    if ($lookup_cache[$cache_key]) {
      require_once ARIAL_ROOT . '/' . $lookup_cache[$cache_key];
    }
    return (bool) $lookup_cache[$cache_key];
  }

  // 这个函数会调用时，默认的数据库是没有激活，
  // 但没有任何理由我们会永远想不使用默认的数据库为这个查询。
  $file = Database::getConnection('default', 'default')->query("SELECT filename FROM {registry} WHERE name = :name AND type = :type", array(
    ':name' => $name,
    ':type' => $type,
  ))
  ->fetchField();

  //我们已经运行了查找查询需要更新缓存的标志。
  $cache_update_needed = TRUE;

  // 错过了值得缓存的有价值的信息,因此缓存即使是$file为FALSE
  $lookup_cache[$cache_key] = $file;

  if ($file) {
    require_once ARIAL_ROOT . '/' . $file;
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * 重新扫描所有启用的模块和重建的注册表。
 * 
 * 重新扫描所有模块中的代码，或包括目录，存储在数据库中的位置，
 * 每一个接口或类。
 */
function registry_rebuild() {
  system_rebuild_module_data();
  registry_update();
}

/**
 * 更新基于注册表的数据库中列出的最新的文件。
 * 
 * 应该使用此功能时不需要system_rebuild_module_data（）被调用，
 * 因为它已是众所周知，列表中的文件{system}表中相匹配的文件系统。
 * 
 * @return 
 *  如果TRUE则注册表的重建，FALSE说明另一个线程并行重建,
 *　当前的线程等待完成。
 * @see registry_rebuild()
 */
function registry_update() {
  // 在安装期间,install_system_module()调用module_enable()
  // 因此锁定系统既没有加载也没它的存储存在
  $in_installer = arial_installation_attempted();
  if (!$in_installer && !lock_acquire(__FUNCTION__)) {
    // 另一个请求获取锁定,直到完成
    lock_wait(__FUNCTION__);
    return FALSE;
  }

  require_once ARIAL_ROOT . '/includes/registry.inc';
  _registry_update();

  if (!$in_installer) {
    lock_release(__FUNCTION__);
  }
  return TRUE;
}

/**
 * @} "addtogroup registry"结束
 */

/**
 * 提供静态变量的存储中心。
 * 
 * 所有的函数需要一个静态变量保存或缓存中的数据在一个单一的页面请
 * 求被鼓励使用这个功能，除非它是绝对肯定的是，静态变量将不再需要
 * 在页面请求复位。通过集中静态变量的存储是通过此功能，其他的功能
 * 可以依靠一个统一的API，用于重置任何其他函数的静态变量。
 *
 * 例如:
 * @code
 * function language_list($field = 'language') {
 *  $language = &arial_static(__FUNCTION__);
 *  if (!isset($languages)) {
 *    //如果这个函数在重置之后第一次使用,查询数据库并执行其他
 *　　//关于支持语言信息需要的代码
 *　　...
 *  }
 * if (!isset($language[$field])) {
 *    //如果这个函数在重置之后第一次使用$field为索引的数组,
 *　  //然后执行代码所需要的索引所需的字段信息已经可以在$language.
 *     ...
 *    }
 *  // 后续调用这个函数为一个特定的索引字段跳过上述两个代码块，
 *  // 并迅速返回已建立索引的信息
 *  return $language[$field]; 
 * }
 * function locale_translate_overview_screen() {
 *  // 当构建内容翻译的概览页时,一定要得到全部的信息支持语言.
 *　arial_static_reset('language_list');
 *  ...
 * }
 * @endcode
 *
 * 在少数情况下，需要一个可复位的静态变量的函数，但该函数被调
 * 用多次（100 +）在一个单一的页面请求，所以每微秒的执行时间，
 * 可以删除的功能计数。
 * 
 * 这些功能可以使用较为繁琐，但速度更快的变种，
 * 调用drupal_static（）。它的工作原理是存储在自己的静态变量调用
 * 函数的返回的引用由drupal_static（），从而消除每一次迭代
 * 的功能需要调用drupal_static（）。
 * 从概念上讲，它替代:
 * @code 
 * $foo = &arial_static(__FUNCTION__)
 * @endcode
 * 和
 * @code
 * // 很遗憾,它还不能工作
 * static $foo = &arial_static(__FUNCTION__);
 * @endcode
 * 可是上面的代码无法正常工作，因为PHP只允许静的变量
 *　被initializied的文字值，并且不允许的静态变量被分配到引用。
 * - http://php.net/manual/en/language.variables.scope.php#language.variables.scope.static
 * - http://php.net/manual/en/language.variables.scope.php#language.variables.scope.references
 * 下面的例子显示了所需的语法来解决双方的限制。对于基准和更多
 * 的信息，看到http://arial.org/node/619666。
 *
 * 例:
 * @code
 * function user_access($string, $account = NULL) {
 *   // 使用 arial_static() 的高级模式匹配, 由于这个函数经常使用.
 *   static $arial_static_fast;
 *   if (!isset($arial_static_fast)) {
 *     $arial_static_fast['perm'] = &arial_static(__FUNCTION__);
 *   }
 *   $perm = &$arial_static_fast['perm'];
 *   ...
 * }
 * @endcode
 * $name 
 *  全局唯一的变量名。
 *  对于一个函数只有一个静态变量，在函数名（例如，通过PHP魔术方法
 *　__FUNCTION__不变）的建议。多个静态变量的函数添加一个显着
 * 的函数名称后缀为每一个.
 *
 * @param $default_value
 *  默认可选值
 * @param $reset
 *  TRUE重新设置一个特定的命名的变量，所有变量$ name是NULL。
 *  应该只用于重置所有的变量，例如，一个干净的环境中运行单元测试。 * @return 
 * 返回一个变量的引用.
 * 
 * @see arial_static_reset()
 */
function &arial_static($name, $default_value = NULL, $reset = FALSE) {
  static $data = array(), $default = array();

  // 首先检查是否先前定义了的静态变量。
  if (isset($data[$name]) || array_key_exists($name, $data)) {
    // $name 和　$data[$name]非空,并且$default[$name]已经存在
    if ($reset) {
      // 现有的静态变量重置为其默认值
      $data[$name] = $default[$name];
    }
    return $data[$name];
  }
  // $data[$name]和$name都没有设置静态变量

  if (isset($name)) {
    if ($reset) {
      // 被称为复位前的默认设置，但必须返回变量。
      return $data;
    }
    // 第一次调用新的非NULL$name。初始化一个新的静态变量。
    $default[$name] = $data[$name] = $default_value;
    return $data[$name];
  }
  // 重置所有：（$name== NULL）。这需要做一次一个.
  // 使早期的drupal_static（）调用返回的引用也得到复位。
  foreach ($default as $name => $value) {
    $data[$name] = $value;
  }
  // 该函数返回一个引用，返回的应该永远是一个变量。
  return $data;
}

/**
 * 重置一个或全部集中存储的静态变量。
 *
 * @param $name
 *  名称的静态变量复位。省略所有变量重置。
 */
function arial_static_reset($name = NULL) {
  arial_static($name, NULL, TRUE);
}

/**
 * 检测是否当前的脚本运行在命令行环境。
 */
function arial_is_cli() {
  return (!isset($_SERVER['SERVER_SOFTWARE']) && (php_sapi_name() == 'cli' || (is_numberic($_SERVER['argc']) && $_SERVER['argc'] > 0)));
}

/**
 * 强调显示在一个句子中的占位符的格式文本。自动使用FORMAT_STRING()
 *
 * 自动使用FORMAT_STRING()
 * @param $text
 *  格式化文本
 * 
 * @return 
 *  被格式化的文本
 */
function arial_placeholder($text) {
  return '<em class="placeholder">' . check_plain($text) . '</em>';
}

/**
 * 注册在关机时执行的功能。
 * 包装register_shutdown_function（）来捕获抛出的异常，
 * 以避免“抛出的异常无需堆栈帧中的未知”。
 * 
 * @param $callback
 *  关闭函数注册
 * @param ...
 *  其他参数
 * 
 * @return 
 *  关机功能将被执行的数组
 *
 * @see register_shutdown_function()
 * @ingroup php_wrappers
 */
function &arial_register_shutdown_function($callback) {
  // 我们不能用arial_static()在这里，因为静态缓存是在
  // 批处理过程中，arial_static会打破批量处理复位。
  static $callbacks = array();

  if (isset($callback)) {
    // 只登记一次内部关闭功能。
    if (empty($callbacks)) {
      register_shutdown_function('_arial_shutdown_function');
    }
    $args = func_get_args();
    array_shift($args);
    // 保存回调和参数
    $callbacks[] = array('callback' => $callback, 'arguments' => $args);
  }
  return $callbacks;
}

/**
 * 执行注册的关闭功能。
 */
function _arial_shutdown_function() {
  $callbacks = &arial_register_shutdown_function();

  // 设置的CWD，以ARIAL_ROOT，因为它是不能保证是相同的，
  // 因为它是在正常的上下文中执行。
  chdir(ARIAL_ROOT);
  try {
    while (list($key, $callback) = each ($callbacks)) {
      call_user_func_array($callback['callback'], $callback['arguments']);
    }
  }
  catch (Exception $exception) {
    // 如果我们显示错误信息，那么这样做不可能再未捕获的异常被抛出
    require_once ARIAL_ROOT . '/includes/erros.inc';
    if (error_displayable()) {
      print '<h1>没有在关闭函数中捕获错误信息.</h1>';
      print '<p>' . _arial_render_exception_safe($exception) . '</p><hr />';
    }
  }
}
