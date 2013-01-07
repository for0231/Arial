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
      cache_get($this->cid, $data, $this->bin);
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
      if (strpos($cookie_domain, 'www.') ===0 ) {
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

  if (!empty($filename) && $file_exists($filename)) {
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
}

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
  elseif ($option['langcode'] != 'en' && function_exists('locale')) {
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
