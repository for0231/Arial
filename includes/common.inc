<?php

/**
 * @file 
 * 许多Arial模块的通用功能，将需要引用。
 *
 * 这些函数至关重要的,甚至当服务被缓存的页面,
 * 而不是位于的bootstrap.inc。
 */

/**
 * @defgroupp php_wrappers PHP包装器函数
 * @{
 * 包装或自定义的PHP函数的实现的功能。
 *
 * 不会在Arial使用某些PHP函数,相反,会使用Arial的替代函数
 * 例如，对于改进的或更安全的UTF-8的处理，或在Arial RFC兼容的处理的URL。
 * 为了便于使用和记忆,在原生PHP函数之前加'arial_'. 
 * 需要谨慎,并非所有的包装函数支持原生PHP函数相同的参数.
 *
 * 你应该总是在你的代码中使用这些包装函数。
 *
 * 错误:
 * @code 
 *  $my_substring = substr($original_string, 0, 5);
 * @endcode
 *
 * 正确:
 * @code
 *  $my_substring = arial_substr($original_string, 0, 5);
 * @endcode
 *
 * @}
 */

/**
 * 返回一个新建项目的'保存'状态.
 */
define ('SAVED_NEW', 1);

/**
 * 返回一个保存更新已有项目的状态.
 */
define ('SAVED_UPDATED', 2);

/**
 * 返回一个删除已有项目的状态.
 */
define ('SAVED_DELETED', 3);

/**
 * 系统CSS文件默认的组添加到页面中。
 */
define ('CSS_SYSTEM', -100);

/**
 * 模块CSS文件默认的组添加到页面中。
 */
define ('CSS_DEFAULT', 0);

/**
 * 主题CSS文件默认的组添加到页面中。
 */
define ('CSS_THEME', 100);

/**
 * 系统Javascript和Jquery库文件默认的组添加到页面中。
 */
define ('JS_LIBRARY', -100);

/**
 * 模块Javascript和Jquery库文件默认的组添加到页面中。
 */
define ('JS_DEFAULT', 0);

/**
 * 主题Javascript和Jquery库文件默认的组添加到页面中。
 */
define ('JS_THEME', 100);

/**
 * @defgroup block_caching Block Caching
 * @{
 * 定义每个块的缓存状态,常量。
 * 
 * 模块指定的块它们可以被缓存在hook_block_info()的实现函数里.
 * 缓存可以被关闭(ARIAL_NO_CACHE),通过模块的区块声明
 * ARIAL_CACHE_CUSTOM, 或者通过核心区块模块.如果区块模块管理
 * 缓存,你可以指定与区块相同的每一页和用户(ARIAL_CACHE_GLOBAL)
 * 或者,取决于页面上它可以改变(ARIAL_CACHE_PER_PAGE)或者通过
 * 用户或角色改变.(ARIAL_CACHE_PER_ROLE或ARIAL_CACHE_PER_USER)
 * .页和用户设置的按位的二进制或操作员可以结合;例:
 *　ARIAL_CACHE_PER_ROLE | ARIAL_CACHE_PER_PAGE 意思是区块可以
 * 基于用户角色和基于页面上修改.
 * 
 * 区块缓存,执行cache_clear_all()后将被清除.并且使用相同的
 * 策略清除其他缓存(node, comment, user, taxonomy　...)
 *
 * 如果块需要更细粒度的清除可以考虑禁用内置的块
 * 缓存（DRUPAL_NO_CACHE），并推出自己的。
 */

/**
 * 不应该缓存的区块。
 *
 * 应使用此设置：
 * - 对于简单的块（尤其是那些不执行任何数据库查询），
 *   其中，查询数据库高速缓存比直接生成的内容将更加昂贵。
 * - 对于块，改变过于频繁。
 */
define ('ARIAL_NO_CACHE', -1);

/**
 * 在hook_block_view()实现函数中处理区块缓存.
 * 
 * 当标准区块基于时间的过期或一个节点访问一个站点缓存无效时,
 * 此设置有效.
 */
define ('ARIAL_CACHE_CUSTOM', -2);

/**
 * 基于用户的角色可以改变区块或元素.
 * 当区块没有指定任何值时,使用区块的默认设置.
 */
define ('ARIAL_CACHE_PER_ROLE', 0x0001);

/**
 * 基于用户可以修改区块或元素.
 * 此设置可以是资源消耗型的网站，大量的用户，
 * 并因此应该只用在DRUPAL_CACHE_PER_ROLE是不够的。
 */
define ('ARIAL_CACHE_PER_USER', 0x0002);

/**
 * 区块或元素依靠页面的变化而变化.
 */
define ('ARIAL_CACHE_PER_PAGE', 0x0004);

/**
 * 对于每一个用户或页面,区块或元素是相同的.
 */
define ('ARIAL_CACHE_GLOBAL', 0x0008);

/**
 * @} "defgroup block_caching" 结束
 */

/**
 * 添加内容到一个特定的区域。
 *　
 * @param $region
 *  被指定添加内容的区域
 * @param $data
 *  添加的内容
 */
function arial_add_region_content($region = NULL, $data = NULL) {
  static $content = array();

  if (isset($region) && isset($data)) {
    $content[$region][] = $data;
  }
  return $content;
}

/**
 * 获取一个给定的区域被分配的内容。
 *
 * @param $region
 *  一个指定的区域获取内容。如果为NULL，所有地区都将被返回。
 * @param $delimiter
 *  分隔符
 */
function arial_get_region_content($region = NULL, $delimiter = '') {
  $content = arial_add_region_content();
  if (isset($region)) {
    if (isset($content[$region]) && is_array($content[$region])) {
      return implode($delimiter, $content[$region]);
    }
  }
  else {
    foreach (array_keys($content) as $region) {
      if (is_array($content[$region])) {
        $content[$region] = implode($delimiter, $content[$region]);
      }
    }
    return $content;
  }
}

/**
 * 获取当前活动的安装配置文件的名称。
 *
 * 当这个函数被调用,在Arial的初始安装过程中，
 * 将要安装的配置文件的名称存储在全局的安装状态中。 
 *
 * 在所有其他时间，标准Arial系统变量表中包含当前配置文件的名
 * 称，我们可以调用variable_get的(),并确定哪一个处于活动状态.
 *
 * @return @profile
 *  安装配置文件的名字.
 */
function arial_get_profile() {
  global $install_state;
  
  if (isset($install_state['parameters']['profile'])) {
    $profile = $install_state['parameters']['profile'];
  }
  else {
    $profile = variable_get('install_profile', 'standard');
  }

  return $profile;
}

/**
 * 设置当前页面的面包屑导航。
 *
 * @param $breadcrumb
 *  一个数组连接,'home'打头开始,但不包括当前页.
 */
function arial_set_breadcrumb($breadcrumb = NULL) {
  $stored_breadcrumb = &arial_static(__FUNCTION__);

  if (isset($breadcrumb)) {
    $stored_breadcrumb = $breadcrumb;
  }
  return $stored_breadcrumb;
}

/**
 * 获取当前页面包屑导航。
 */
function arial_get_breadcrumb() {
  $breadcrumb = arial_set_breadcrumb();

  if (!isset($breadcrumb)) {
    $breadcrumb = menu_get_active_breadcrumb();
  }

  return $breadcrumb;
}

/**
 * 返回一个字符串，其中包含RDF命名空间声明中使用的XML和XHTML输出。
 */
function arial_get_rdf_namespaces() {
  $xml_rdf_namespaces = array();

  // 序列化的RDF在XML命名空间的命名空间语法。
  if (function_exists('rdf_get_namespaces')) {
    foreach (rdf_get_namespaces() as $prefix => $uri) {
      $xml_rdf_namespaces[] = 'xmlns:' . $prefix . '="' . $uri. '"';
    }
  }
  return count($xml_rdf_namespaces) ? "\n  " .implode("\n  ", $xml_rdf_namespaces) : '';
}

/**
 * 添加输出的HTML页面的HEAD标签。
 * 
 * 如果页头没有被发送则调用此函数。不传参(或传NULL)
 * 则检索存储的元素。
 *
 * @param $data
 *  一个可渲染的数组,如果'#type'键没有设置,则'html_tag'将被
 * 添加作为'#type'的默认值.
 *
 * @param $key
 *  一个唯一的字符串键允许实现hook_html_head_alter()
 *　来识别$data中的元素。如果$data是不为NULL。
 * 
 * @return 
 *  存储的所有的HEAD元素的数组。
 *
 * @see theme_html_tag().
 */
function arial_add_html_head($data = NULL, $key = NULL) {
  $stored_head = &arial_static(__FUNCTION__);
  
  if (!isset($stored_head)) {
    // 首先确保包括内容类型，默认值.
    $stored_head = _arial_default_html_head();
  }

  if (isset($data) && isset($key)) {
    if (!isset($data['#type'])) {
      $data['#type'] = 'html_tag';
    }
    $stored_head[$key] = $data;
  }
  return $stored_head;
}

/**
 * 返回总是显示在HTML页面的HEAD标签.
 */
function _arial_default_html_head() {
  // 添加默认元素,首先确认内容类型,这是因为IE浏览器可能会受
  // 到攻击，在此之前META标记，如TITLE标签编码攻击XSS通过。
  $elements['system_meta_content_type'] = array(
    '#type' => 'html_tag',
    '#tag'  => 'meta',
    '#attributes' => array(
      'http-equiv' => 'Content-Type',
      'content'    => 'text/html; charset=utf-8',
    ),
    // 安全性：这总是有第一输出。
    '#weight' => -1000,
  );

  // 显示Arial和主版本号在META通用标记,并取得的主要版本。
  list($version, ) = explode('.', VERSION);
  $elements['system_meta_generator'] = array(
    '#type'   => 'html_tag',
    '#tag'    => 'meta',
    '#attributes' => array(
      'name' => 'Generator',
      'content' => 'Arial ' . $version . ' (http://arial.org',
    ),
  );
  // 同时发送的HTTP标头中的Generator。
  $elements['system_meta_generator']['#attached']['arial_add_http_header'][] = array('X-Generator', $elements['system_meta_generator']['#attributes']['content']);

  return $elements;
}

/**
 * 检索HTML页面的并显示HEAD标签的输出.
 */
function arial_get_html_head() {
  $elements = arial_add_html_head();
  arial_alter('html_head', $elements);
  return arial_render($elements);
}

/**
 * 在当前页添加一个Feed链接
 * 可以调用这个函数，只要尚未发送的HTML头。
 * 
 * @param $url
 *  内部路径或完全格式的外部路径.
 * @param $title
 *  Feed标题
 */
function arial_add_feed($url = NULL, $title = '') {
  $stored_feed_links = &arial_static(__FUNCTION__, array());

  if (isset($url)) {
    $stored_feed_links[$url] = theme('feed_icon', array('url' => $url, 'title' => $title));

    arial_add_html_head_link(array(
      'rel' => 'alternate',
      'type' => 'application/rss+xml',
      'title' => $title,
      // 强制使用完整路径,Arial输出与其他的<link>一致.
      'href' => url($url, array('absolute' => TRUE)),
    ));
  }
  return $stored_feed_links;
}

/**
 * 获取当前页面的Feed的URL链接。
 *
 * @param $delimiter
 *  分隔字符
 */
function arial_get_feeds($delimiter = "\n") {
  $feeds = arial_add_feed();
  return implode($feeds, $delimiter);
}

/**
 * @defgroup http_handling HTTP handling.
 * @{
 * 妥善处理HTTP响应.
 */

/**
 * 处理URL的查询参数数组并删除不需要的元素。
 *
 * @param $query
 * (可选) 一个数组被处理,默认是$_GET.
 * @param $exclude
 * (可选) $query数组列表的键被删除,并使用"parent[child]"排除
 * 嵌套的选项.　默认数组是array('q').
 * @param $parent
 *  仅内部使用,嵌套项目可用于构建查询语句$query.
 *
 * @return 
 *  返回一个数组,其中包含查询参数,也可用于url().
 */
function arial_get_query_parameters(array $query = NULL, array $exclude = array('q'), $parent = '') {
  // 如果$query=NULL,设置默认值
  if (!isset($query)) {
    $query = $GET;
  }

  // 如果$exclude为空,将没有过滤器.
  if (empty($exclude)) {
    return $query;
  }
  elseif (!$parent) {
    $exclude = array_flip($exclude);
  }

  $params = array();
  foreach ($query as $key => $value) {
    $string_key = ($parent ? $parent . '[' . $key . ']' : $key)
    if (isset($exclude[$string_key])) {
      continue;
    }

    if (is_array($value)) {
      $params[$key] = arial_get_query_parameters($value, $exclude, $string_key);
    }
    else {
      $params[$key] = $value;
    }
  }

  return $params;
}

/**
 * 一个URL编码的查询字符串分割成一个数组。
 *
 * @param $query
 *  查询字符串分割。 
 *
 * @return
 *   URL的数组解码夫妇$param_name => $value.
 */
function arial_get_query_array($query) {
  $result = array();
  if (!empty($query)) {
    foreach (explode('&', $query) as $param) {
      $param = explode('=', $param);
      $result[$param[0]] = isset($param[1]) ? rawurldecode($param[1]) : '';
    }
  }
  return $result;
}

/**
 * 解析一个数组转换成一个有效的，原始的url编码的查询字符串。
 * 
 * 这不同于http_build_query()，因为我们需要原始url编码
 * (而不是url编码)的查询参数。
 * 
 * @param $query
 *  查询参数数组以进行处理，例如$ _GET。
 * @param $parent
 *  仅供内部使用。用于为嵌套的项目构建$query数组的键。
 * @return 
 *  一个原始url编码的字符串，它可以被用来作为，或附加到
 * URL查询字符串。
 *
 * @see arial_get_query_parameters()
 * @ingroup php_wrappers
 */
function arial_http_build_query(array $query, $parent = '') {
  $params = array();

  foreach ($query as $key => $value) {
    $key = ($parent ? $parent . '[' . rawurlencode($key) . ']' : rawurlencode($key));

    // 递归子数组
    if (is_array($value)) {
      $params[] = arial_http_build_query($value, $key);
    }
    // 如果一个查询参数为NULL,仅添加它的键.
    else {
      // 为了更好的可读性查询字符串中的路径，解码斜线。
      $params[] = $key . '=' . str_replace('%2F', '/', rawurlencode($value));
    }
  }

  return implode('&', $params);
}

/**
 * 为使用arial_goto()准备一个'destination'URL查询参数
 *
 * 用于引导用户到引用页填写表格后，默认情况下，当前的URL返回。
 * 如果目的地中存在先前的请求，则返回该目的地。因此，
 * 一个目标可以坚持跨越多个页面。 
 *
 * @return 
 *  返回一个关联数组包含的键:
 *  - destination: 通过的目的地查询字符串或提供的路径，
 *     如果没有可用的当前路径。
 * 
 * @see current_path()
 * @see arial_goto()
 */
function arial_get_destination() {
  $destination = &arial_static(__FUNCTION__);

  if (isset($destination)) {
    return $destination;
  }

  if (isset($_GET['destination'])) {
    $destination = array('destination' => $_GET['destination']);
  }
  else {
    $path = $_GET['q'];
    $query = arial_http_build_query(arial_get_query_parameters());
    if ($query != '') {
      $path .= '?' . $query;
    }
    $destination = array('destination' => $path);
  }
  return $destination;  
}

/**
 * 解析一个的系统URL字符串转换成一个关联数组，适用于url()。
 * 
 * 该函数只应被用于已经由系统生成的URL，例如通过网址url().
 * 它不应该被用于来自外部来源的URL，或URL链接到外部资源。
 * 返回的数组包含一个'path'可能通过单独的url().
 *
 * 例:
 * @code
 *  $options = arial_parse_url($_GET['destination']);
 *  $my_url  = url($options['path'], $options);
 *  $my_link = l('示例链接', $options['path'], $options)
 * @endcode
 *
 * 这是必须的,因为url()因为不支持相对URL中的查询字符串
 * 或片段在$ path参数。相反，任何查询字符串需要被解析到
 * 一个关联查询参数数组$options['query']和$options['fragment']
 * 插入片段。
 *
 * @param $url
 *  解析的url字串,例:　$_GET['destination']
 *
 * @return 
 *  一个关联数组包含以下键值:
 * - 'path': URL路径,如果给的$url是扩展的,那么$url包含模式和主机名　
 * - 'query': $url的查询参数数组.如果存在的话.
 * - 'fragment': $url片段,如果存在的话.
 * 
 * @see url()
 * @see arial_goto()
 * @ingroup php_wrappers
 */
function arial_parse_url($url) {
  $options = array(
    'path' => NULL,
    'query' => array(),
    'fragment' => '',
  );

  // 外部urls:这里不用parse_url(),因此我们不会重新构建模式,
  // 主机名和路径
  if (strpos($url, '://') !== FALSE) {
    // 将查询路径进入'path'之前分隔
    $parts = explode('?', $url);
    $options['path'] = $parts[0];
    // 如果存在一个查询字串,转换并导入查询参数.
    if (isset($parts[1])) {
      $query_parts = explode('#', $parts[1]);
      parse_str($query_parts[0], $options['query']);
      // 接管片段,如果存在
      if (isset($query_parts[1])) {
        $options['fragment'] = $query_parts[1];
      }
    }
  }
  // 内部URLs
  else {
    // parse_url()不支持相关性URLs,因此使用绝对路径,例:相对
    // 路径"foo/bar:1"不合适解析.
    $parts = parse_url('http://example.com/' . $url);
    // 剥离刚刚加入的领先的斜线
    $options['path'] = substr($parts['path'], 1);
    if (isset($parts['query'])) {
      parse_str($parts['query'], $options['query']);
    }
    if (isset($parts['fragment'])) {
      $options['fragment'] = $parts['fragment'];
    }
  }
  // 如果简洁链接模式没有启动,则q参数包含当前页路径.
  // 当简洁链接模式存在的时候,重写路径,
  if (isset($options['query']['q'])) {
    $options['path'] = $options['query']['q'];
    unset($options['query']['q'];
  }

  return $options;
}

/**
 * 给使用中的URL编码一个Arial路径
 * 出于美观的考虑斜线没能转义.
 * 
 * 注意：URL()调用此函数需要注意，所以传递给该函数的路径
 * 不应该提前进行编码。
 *
 * @param $path
 *  需要编码的URL
 */
function arial_encode_path($path) {
  return str_replace('%2F', '/', rawurlencode($path));
}

/**
 * 发送用户到一个不同的Arial 页面
 *
 * 有一个HTTP地址转向问题,这个函数保证转向使用正确的格式
 * 
 * 通常情况下，重定向的URL构造函数的输入参数。
 * 但是，您可以覆盖该行为，通过设定一个目标在$ _REQUEST数组
 *（即使用查询字符串的URI）这是用来引导用户到正确的页面后填写
 * 表格。例如，在修改后的“管理/内容页或登录后使用侧边栏
 * 的”user login'区块。arial_get_detination()函数帮助设置目标URL
 *
 * Arial用arial_set_message()设置信息和其他会话数据会被写入数据
 * 库在跳转之前.
 *
 * @param $path
 * (可选) 一个Arial路径或一个全链接路径,将会被传入url()完成跳转
 * 
 * @param $options
 * (可选) 一个额外的URL选项关联数组将会传入url().
 * @param $http_response_code
 * (可选) HTTP状态码用作跳转,默认302,有效值是3xx,均为跳转状态码
 * 跳转状态码在此链接定义
 * @link http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html
 *   #sec10.3 RFC 2616
 * @endlink
 * - 301: 永久移动（重定向的推荐值）。
 * - 302: 查找到（默认在Arial和PHP，有时也用于垃圾邮件的搜索引擎）。
 * - 303: 查看其他.
 * - 304: 不能修改
 * - 305: 使用代理
 * - 307: 暂时跳转
 *
 * @see arial_get_destination()
 * @see url()
 */
function arial_goto($path = '', array $options = array(), $http_response_code = 302) {
  // 一个目的地址始终覆盖在$_GET函数的参数。
  // 不允许绝对地址从$_GET传入,这可能是一个攻击向量
  if (isset($_GET['destination']) && !url_is_external($_GET['destination'])) {
    $destination = arial_parse_url($_GET['destination']);
    $path = $destination['path'];
    $options['query'] = $destination['query'];
    $options['fragment'] = $destination['fragment'];
  }

  arial_alter('arial_goto', $path, $options, $http_response_code);

  // 定位HTTP头,必须是绝对地址.
  $options['absolute'] = TRUE;

  $url = url($path, $options);

  header('Location: ' . $url, TRUE, $http_response_code);

  arial_exit($url); 
}

/**
 * 提供了“网站正在维护中”的消息浏览器。
 * 
 * 页面回调函数想报告一个“网站离线”的消息，
 * 应返回MENU SITE_OFFLINE的，而不是调用：Arial
 * 的site_offline()。然而，在上下文中，返回值可能不能上升到
 * menu_execute_active_handler()应该调用arial_site_offline()
 * 函数被调用。
 */
function arial_site_offline() {
  arial_deliver_page(MENU_SITE_OFFLINE);
}

/**
 * 提供了一个“找不到网页”错误的浏览器。
 * 
 * 想要报告“访问被拒绝”的消息应该返回菜单页的回调函数，
 * 而不是_ACCESS_DENIED调用arial_access_denied().
 */
function arial_access_denied() {
  arial_deliver_page(MENU_ACCESS_DENIED);
}

/**
 * 执行一个HTTP请求
 *
 * 这是一个灵活，功能强大的HTTP客户端实现。
 * 正确处理GET，POST，PUT或任何其他的HTTP请求。处理重定向。
 * 
 * @param $url
 *  一个字符串，其中包含一个完全合格的URI。
 * @param array $options
 *  (可选) 数组，可以有一个或多个下列元素：
 * - headers: 一个数组，包含请求标头发送的名称/值对。
 * - method: 一个字符串，包含请求的方法。默认为“GET”。
 * - data: 一个字符串，包含请求主体，格式为“参数=值＆参数=值＆...”。默认设置为NULL。
 * - max_redirects: 一个整数，表示有多少次重定向可能会紧随其后。默认值为3。
 * - timeout: 函数的调用可能需要一个浮动的最大秒数。默认值是30秒。如果发生超时，错误代码设置的HTTP_REQUEST_TIMEOUT常数。
 * - context: 上下文创建的资源与stream_context_create().
 * 
 * @return object
 *  一个对象，该对象可以具有一个或多个以下组件：
 *  - request: 一个字符串，其中包含已发送请求的主体。
 *  - code: 响应状态代码或错误代码包含一个整数，如果发生了错误
 *  - protocol: 通讯协议（如HTTP/1.1或HTTP/1.0）。
 *  - status_message: 状态消息的回应，如果收到了一个响应。
 *  - redirect_url: 如果重定向，一个字符串，其中包含的重定向的目标URL。
 *  - error: 如果发生了错误，该错误消息。否则，没有设置。
 *  - headers: 一个数组，包含名称/值对的响应头。
 *    HTTP标头名称是区分大小写的（RFC 2616第4.2节），
 *    所以在较低的情况下方便地访问数组的键返回。
 *  - data: 一个字符串，包含接收到的响应体。
 */
function arial_http_request($url, array $options = array()) {
  $result = new stdClass();

  // 解析URL，并确保我们可以处理模式。.
  $uri = @parse_url($url);

  if ($uri == FALSE) {
    $result->error = 'unable to parse URL';
    $result->code = -1001;
    return $result;
  }

  if (!isset($uri['scheme'])) {
    $result->error = 'missing schema';
    $result->code = -1002;
    return $result;
  }

  timer_start(__FUNCTION__);

  // 合并默认选项.
  $options += array(
    'headers' => array(),
    'method' => 'GET',
    'data' => NULL,
    'max_redirects' => 3,
    'timeout' => 30.0,
    'context' => NULL,
  );

  // 合并默认头信息.
  $options['headers'] += array(
    'User-Agent' => 'Arial (+http://arial.org/)',
  );

  // stream_socket_client() 需要浮点超时数.
  $options['timeout'] = (float) $options['timeout'];

  // 如果定义了主机不排除列表中使用代理.
  $proxy_server = variable_get('proxy_server', '');
  if ($proxy_server && _arial_http_use_proxy($uri['host'])) {
    // 设置一个模式以便我们打开一个套接字的代理服务器.
    $uri['scheme'] = 'proxy';
    // 设置为Full URL到路径.
    $uri['path'] = $url;
    // 由于URL传递到路径，因此我们不会使用解析查询.
    unset($uri['query']);

    // 如果需要的话添加用户名和密码到代理认证头部.
    if ($proxy_username = variable_get('proxy_username', '')) {
      $proxy_password = variable_get('proxy_password', '');
      $options['headers']['Proxy-Authorization'] = 'Basic ' . base64_encode($proxy_username . (!empty($proxy_password) ? ":" . $proxy_password : ''));
    }
    // 一些代理拒绝任何的User-Agent头的请求，而有些则需要一个特定的.
    $proxy_user_agent = variable_get('proxy_user_agent', '');
    // 默认值两个条件都不符合.
    if ($proxy_user_agent === NULL) {
      unset($options['headers']['User-Agent']);
    }
    elseif ($proxy_user_agent) {
      $options['headers']['User-Agent'] = $proxy_user_agent;
    }
  }

  switch ($uri['scheme']) {
    case 'proxy':
      // 使套接字连接到代理服务器.
      $socket = 'tcp://' . $proxy_server . ':' . variable_get('proxy_port', 8080);
      // 主机头仍然需要符合实际的要求.
      $options['headers']['Host'] = $uri['host'];
      $options['headers']['Host'] .= isset($uri['port']) && $uri['port'] != 80 ? ':' . $uri['port'] : '';
      break;

    case 'http':
    case 'feed':
      $port = isset($uri['port']) ? $uri['port'] : 80;
      $socket = 'tcp://' . $uri['host'] . ':' . $port;
      // RFC 2616：“非标准端口必须（MUST），默认的端口可能被列入”。我们不添加标准的端口，
      // 以防止破重写规则检查主机没有考虑到的端口号.
      $options['headers']['Host'] = $uri['host'] . ($port != 80 ? ':' . $port : '');
      break;

    case 'https':
      // 注：只有工作时，PHP编译时支持OpenSSL.
      $port = isset($uri['port']) ? $uri['port'] : 443;
      $socket = 'ssl://' . $uri['host'] . ':' . $port;
      $options['headers']['Host'] = $uri['host'] . ($port != 443 ? ':' . $port : '');
      break;

    default:
      $result->error = 'invalid schema ' . $uri['scheme'];
      $result->code = -1003;
      return $result;
  }

  if (empty($options['context'])) {
    $fp = @stream_socket_client($socket, $errno, $errstr, $options['timeout']);
  }
  else {
    // 建立流与上下文。可以验证的SSL证书.
    $fp = @stream_socket_client($socket, $errno, $errstr, $options['timeout'], STREAM_CLIENT_CONNECT, $options['context']);
  }

  // 确保正确打开Socket.
  if (!$fp) {
    // 当出现网络错误，我们使用了负数，所以它不冲突的HTTP状态码.
    $result->code = -$errno;
    $result->error = trim($errstr) ? trim($errstr) : t('Error opening socket @socket', array('@socket' => $socket));

    // 标记申请失败。这将触发一个检查Web服务器的传出HTTP请求的能力，使下一次的要求进行检查.
    // 查看System_Requirements().
    variable_set('arial_http_request_fails', TRUE);

    return $result;
  }

  // 构建当前激活的路径.
  $path = isset($uri['path']) ? $uri['path'] : '/';
  if (isset($uri['query'])) {
    $path .= '?' . $uri['query'];
  }

  // 仅Content-Length添加如果我们任何内容，或如果它是一个POST或PUT请求。一些非标准的服务器
  // 上的Content-Length感到困惑，至少在HEAD/ GET请求，在POST/PUT请求中squid总是
  // 需要的Content-Length.
  $content_length = strlen($options['data']);
  if ($content_length > 0 || $options['method'] == 'POST' || $options['method'] == 'PUT') {
    $options['headers']['Content-Length'] = $content_length;
  }

  // 如果服务器的URL有一个用户，然后再尝试使用基本身份验证.
  if (isset($uri['user'])) {
    $options['headers']['Authorization'] = 'Basic ' . base64_encode($uri['user'] . (isset($uri['pass']) ? ':' . $uri['pass'] : ''));
  }

  // 如果正在使用的数据库前缀SimpleTest的运行测试，在复制的数据库，然后设置User-Agent头，
  // 因此，任何调用其他Arial的页面将运行SimpleTest的前缀数据库的数据库前缀。用户代理使用，
  // 以确保在同一时间运行多个测试会话不会互相干扰，因为他们如果数据库前缀被静态地存储在文
  // 件或数据库中的变量.
  $test_info = &$GLOBALS['arial_test_info'];
  if (!empty($test_info['test_run_id'])) {
    $options['headers']['User-Agent'] = arial_generate_test_ua($test_info['test_run_id']);
  }

  $request = $options['method'] . ' ' . $path . " HTTP/1.0\r\n";
  foreach ($options['headers'] as $name => $value) {
    $request .= $name . ': ' . trim($value) . "\r\n";
  }
  $request .= "\r\n" . $options['data'];
  $result->request = $request;
  // 计算多少时间留下的原始的超时值.
  $timeout = $options['timeout'] - timer_read(__FUNCTION__) / 1000;
  if ($timeout > 0) {
    stream_set_timeout($fp, floor($timeout), floor(1000000 * fmod($timeout, 1)));
    fwrite($fp, $request);
  }

  // 取响应。由于如http://bugs.php.net/bug.php?id=43782和http://bugs.php.net/bug.php?id=46049 PHP错误，我们不能依靠的feof()，但是，而不是必须调用stream_get_meta_data()每次迭代.
  $info = stream_get_meta_data($fp);
  $alive = !$info['eof'] && !$info['timed_out'];
  $response = '';

  while ($alive) {
    // 计算多少时间留下的原始的超时值.
    $timeout = $options['timeout'] - timer_read(__FUNCTION__) / 1000;
    if ($timeout <= 0) {
      $info['timed_out'] = TRUE;
      break;
    }
    stream_set_timeout($fp, floor($timeout), floor(1000000 * fmod($timeout, 1)));
    $chunk = fread($fp, 1024);
    $response .= $chunk;
    $info = stream_get_meta_data($fp);
    $alive = !$info['eof'] && !$info['timed_out'] && $chunk;
  }
  fclose($fp);

  if ($info['timed_out']) {
    $result->code = HTTP_REQUEST_TIMEOUT;
    $result->error = 'request timed out';
    return $result;
  }
  // 解析响应头的响应体。要查找的HTTP响应单独的头和主体\n\n或\r\r替换\r\n\r\n.
  list($response, $result->data) = preg_split("/\r\n\r\n|\n\n|\r\r/", $response, 2);
  $response = preg_split("/\r\n|\n|\r/", $response);

  // 解析响应状态行.
  list($protocol, $code, $status_message) = explode(' ', trim(array_shift($response)), 3);
  $result->protocol = $protocol;
  $result->status_message = $status_message;

  $result->headers = array();

  // 解析响应报头.
  while ($line = trim(array_shift($response))) {
    list($name, $value) = explode(':', $line, 2);
    $name = strtolower($name);
    if (isset($result->headers[$name]) && $name == 'set-cookie') {
      // RFC 2109的Set-Cookie响应头包含令牌的Set-Cookie，其次是一个逗号分隔的列表中的一个
      // 或多个Cookie.
      $result->headers[$name] .= ',' . trim($value);
    }
    else {
      $result->headers[$name] = trim($value);
    }
  }

  $responses = array(
    100 => 'Continue',
    101 => 'Switching Protocols',
    200 => 'OK',
    201 => 'Created',
    202 => 'Accepted',
    203 => 'Non-Authoritative Information',
    204 => 'No Content',
    205 => 'Reset Content',
    206 => 'Partial Content',
    300 => 'Multiple Choices',
    301 => 'Moved Permanently',
    302 => 'Found',
    303 => 'See Other',
    304 => 'Not Modified',
    305 => 'Use Proxy',
    307 => 'Temporary Redirect',
    400 => 'Bad Request',
    401 => 'Unauthorized',
    402 => 'Payment Required',
    403 => 'Forbidden',
    404 => 'Not Found',
    405 => 'Method Not Allowed',
    406 => 'Not Acceptable',
    407 => 'Proxy Authentication Required',
    408 => 'Request Time-out',
    409 => 'Conflict',
    410 => 'Gone',
    411 => 'Length Required',
    412 => 'Precondition Failed',
    413 => 'Request Entity Too Large',
    414 => 'Request-URI Too Large',
    415 => 'Unsupported Media Type',
    416 => 'Requested range not satisfiable',
    417 => 'Expectation Failed',
    500 => 'Internal Server Error',
    501 => 'Not Implemented',
    502 => 'Bad Gateway',
    503 => 'Service Unavailable',
    504 => 'Gateway Time-out',
    505 => 'HTTP Version not supported',
  );
  // RFC2616规定，所有未知的的HTTP代码必须被视为相同的基本代码.
  if (!isset($responses[$code])) {
    $code = floor($code / 100) * 100;
  }
  $result->code = $code;

  switch ($code) {
    case 200: // OK
    case 304: // 不修改 
      break;
    case 301: // 已被永久移动 
    case 302: // 临时移动 
    case 307: // 临时移动 
      $location = $result->headers['location'];
      $options['timeout'] -= timer_read(__FUNCTION__) / 1000;
      if ($options['timeout'] <= 0) {
        $result->code = HTTP_REQUEST_TIMEOUT;
        $result->error = 'request timed out';
      }
      elseif ($options['max_redirects']) {
        // 重定向到新的位置.
        $options['max_redirects']--;
        $result = arial_http_request($location, $options);
        $result->redirect_code = $code;
      }
      if (!isset($result->redirect_url)) {
        $result->redirect_url = $location;
      }
      break;
    default:
      $result->error = $status_message;
  }

  return $result;
}

/**
 * 使用帮助函数从需要的代理上决定主机排除.
 *
 * @return 
 *  如果返回TRUE,则应该使用这个主机
 */
function _arial_http_use_proxy($host) {
  $proxy_exceptions = variable_get('proxy_exceptions', array('localhost', '127.0.0.1'));
  return !in_array(strtolower($host), $proxy_exceptions, TRUE);
}

/**
 * @} "HTTP处理"结束
 */

/**
 * 过滤字符串或数组的斜线
 * 
 * 在fix_gpx_magic()中调用array_walk()函数
 *
 * @param $item
 *  超全局中独立的字符串或数组
 */
function _fix_gpc_magic(&$item) {
  if (is_array($item)) {
    array_walk($item, '_fix_gpc_magic');
  }
  else {
    $item = stripslashes($item);
  }
}

/**
 * 过滤$_FILES中的斜线
 *
 * 在fix_gpx_magic()中调用array_walk()函数
 *
 * @param $item
 *  $_FILES中的项
 * @param $key
 *  $_FILES中的键
 *
 * @see http://php.net/manual/en/features.file-upload.php#42280
 */
function _fix_gpc_magic_files(&$item, $key) {
  if ($key != 'tmp_name') {
    if (is_array($item)) {
      array_walk($item, '_fix_gpc_magic_files');
    }
    else {
      $item = stripslashes($item);
    }
  }
}

/**
 * 修正了双转义一些PHP的安装所造成的“魔术引号”.
 *　
 * @see _fix_gpc_magic()
 * @see _fix_gpc_magic_files()
 */
function fix_gpc_magic() {
  static $fixed = FALSE;
  if (!$fixed && ini_get('magic_quotes_gpc')) {
    array_walk($_GET, '_fix_gpc_magic');
    array_walk($_POST, '_fix_gpc_magic');
    array_walk($_COOKIE, '_fix_gpc_magic');
    array_walk($_REQUEST, '_fix_gpc_magic');
    array_walk($_FILES, '_fix_gpc_magic_files');
  }
  $fixed = TRUE
}

/**
 * @defgroup 输入验证
 * @{
 * 用户输入验证函数
 */

/**
 * 较验邮件地址
 * 
 * 查看细节
 * @link 
 *  http://tools.ietf.org/html/rfc5321 RFC 5321 
 * @endlink
 *
 * @param $mail
 *  邮件地址
 * @return 
 *  如果是有效的邮件地址,则返回TRUE.
 */
function valid_email_address($mail) {
  return (bool)filter_var($mail, FILTER_VALIDATE_EMAIL);
}

/**
 * 验证给定的URL的语法
 * 
 * 此功能只能用于实际的URL。它不应该被用于Drupal的菜单
 * 路径，它可以包含任意字符。每个RFC 3986的有效值.
 * 
 * @param $url
 *  需要较验的url
 * @param $aboslute
 *  
 * @return
 *  如果是有效的URL,则返回TRUE
 */
function valid_url($url, $absolute = FALSE) {
  if ($absolute) {
    return (bool)preg_match("
      /^                                                      # Start at the beginning of the text
      (?:ftp|https?|feed):\/\/                                # Look for ftp, http, https or feed schemes
      (?:                                                     # Userinfo (optional) which is typically
        (?:(?:[\w\.\-\+!$&'\(\)*\+,;=]|%[0-9a-f]{2})+:)*      # a username or a username and password
        (?:[\w\.\-\+%!$&'\(\)*\+,;=]|%[0-9a-f]{2})+@          # combination
      )?
      (?:
        (?:[a-z0-9\-\.]|%[0-9a-f]{2})+                        # A domain name or a IPv4 address
        |(?:\[(?:[0-9a-f]{0,4}:)*(?:[0-9a-f]{0,4})\])         # or a well formed IPv6 address
      )
      (?::[0-9]+)?                                            # Server port number (optional)
      (?:[\/|\?]
        (?:[\w#!:\.\?\+=&@$'~*,;\/\(\)\[\]\-]|%[0-9a-f]{2})   # The path and query (optional)
      *)?
    $/xi", $url);
  }
  else {
    return (bool)preg_match("/^(?:[\w#!:\.\?\+=&@$'~*,;\/\(\)\[\]\-]|%[0-9a-f]{2})+$/i", $url);
  }
}

/**
 * @} "defgroup validation"结束
 */

/**
 * 为当前访问者注册洪水控制机制的事件。
 *
 * @param $name
 *  事件名称
 * @param $window
 *  可选的秒数在此事件之前到期。默认为3600(1小时)。通常使用相同的值作
 *  为flood_is_allowed()$window.无限增长，过期事件被清除cron运行,
 *  以防止洪水表.
 * @param $identifier
 *  可选的标识符（默认为当前用户的IP地址）
 */
function flood_register_event($name, $window = 3600, $identifier = NULL) {
  if (!isset($identifier)) {
    $identifier = ip_address();
  }
  db_insert('flood')
    ->fields(array(
      'event' => $name,
      'identifier' => $identifier,
      'timestamp' => REQUEST_TIME,
      'expiration' => REQUEST_TIME + $window,
    ))
    ->execute();
}

/**
 * 洪水控制机制忘了当前访问者的事件。
 *
 * @param $name
 *  事件名称
 * @param $identifier
 *  可选的标识符(默认为当前用户的IP地址).
 */
function flood_clear_event($name, $identifier = NULL) {
  if (!isset($identifier)) {
    $identifier = ip_address();
  }
  db_delete('flood')
    ->condition('event', $name)
    ->condition('identifier', $identifier)
    ->execute();
}

/**
 * 检查用户是否可以处理指定事件
 *
 * 事件可以有说每个用户只能做该事件的时间窗口中的一定数目的次数的阈值
 * 此功能验证，目前用户已超过阈值 
 *
 * @param $name
 *  事件的惟一名
 * @param $threshold
 *  阈值:每个用户能够在一个窗口较验的最大次数
 * @param $window
 *  当前窗口此事件的等待秒数(默认为3600秒或一小时)
 * @param $identifier
 *  当前用户的惟一标识,默认为ip
 * 
 * @return 
 *  如果允许用户处理,则返回为TRUE,如果为假,则不允许用户处理
 *  如果超过了阈值,则不允许用户处理
 */
function flood_is_allowed($name, $threshold, $window = 3600, $identifier = NULL) {
  if (!isset($identifier)) {
    $identifier = ip_address();
  }
  $number = db_query("SELECT COUNT(*) FROM {flood} WHERE event = :event AND identifier = :identifier AND timestamp > :timestamp", array(
    ':event' => $name,
    ':identifier' => $identifier,
    ':timestamp' => REQUEST_TIME - $window))
    ->fetchField();
  return ($number < $threshold);
}

/**
 * @defgroup  消毒函数
 * @{
 *
 * @link http://arial.org/writing-secure-code @endlink 获取更多的信息
 */

/**
 * 过滤URL中的dangerous协议(比如javascript:)
 *
 * 此功能必须要求用户输入之前被输出到一个HTML属性值中的所有URL
 * 它通常被称为部分的check_url()或filter_xss()的，但这些函数返回一
 * 个HTML编码的字符串，所以这个功能可以单独调用时所需的输出是一个纯文
 * 本字符串传递到t()，l()，arial_attributes()，或另一个函数，该函数
 * 将调用分别check_plain().
 *
 * @param $uri
 *  一个纯文本的URI可能包含危险的协议.
 * @return 
 *  剥离的纯文字URI危险的协议。所有的纯文本字符串，返回值必须不被输
 *  出到一个HTML页面，而无需check_plain()被调用就可以了。但是，它可以
 *  被期待的纯文本字符串传递给函数.
 * 
 * @see check_url()
 */
function arial_strip_dangerous_protocols($uri) {
  static $allowed_protocols;

  if (!isset($allowed_protocols)) {
    $allowed_protocols = array_flip(variable_get('filter_allowed_protocols', array('ftp', 'http', 'https', 'irc', 'mailto', 'news', 'nntp', 'rtsp', 'sftp', 'ssh', 'tel', 'telnet', 'webcal')));
  }

  // 反复删除任何无效协议
  do {
    $before = $uri;
    $colonpos = strpos($uri, ':');
    if ($colonpos > 0) {
      // 我们发现了一个冒号，可能是一个协议.　较验它.
      $protocol = substr($uri, 0, $colonpos);
      // 如果冒号前面的斜杠，问号或哈希，它可以没有可能是URL模式的一
      // 部分。这必须是一个相对URL，它继承了（安全）协议的基础文件.
      if (preg_match('![/?#]!', $protocol)) {
        break;
      }
      // 检查如果这是不允许的协议。根据RFC2616，第3.2.3（URI比较）模式
      // 的比较必须是不区分大小写.
      if (!isset($allowed_protocols[strtolower($protocol)])) {
        $uri = substr($uri, $colonpos + 1);
      }
    }
  } while ($before != $uri);

  return $uri;
}

/**
 * 过滤危险的协议从一个URI,并对其进行编码，输出到HTML中。
 * 
 * @param $uri
 *  一个纯文本的URI可能包含危险的协议
 *
 * @return 
 *  一个需URI过滤的危险的协议和编码输出的HTML属性值。因为这已经是编码
 *　的，它不应该被作为一个属性数组传递给arial_attributes()内的值，因
 *  为arial_attributes()预计，这些值是纯文本的字符串。要通过一个过滤
 *  URI的arial_attributes（）调用arial_strip_dangerous_protocols()。
 *  
 * @see arial_strip_dangerous_protocols()
 */
function check_url($uri) {
  return check_plain(arial_strip_dangerous_protocols($uri));
}

/**
 * 管理员只适用于一个非常宽容的XSS / HTML过滤器
 * 
 * 使用字段，它是不适合使用的整个过滤系统，但其中一些（主要是内联）
 * 的标志，是理想的（所以check_plain（）是不能接受的）
 * 
 * 允许所有的标签，可以用来在HTML的主体，保存脚本和样式
 */
function filter_xss_admin($string) {
  return filter_xss($string, array('a', 'abbr', 'acronym', 'address', 'article', 'aside', 'b', 'bdi', 'bdo', 'big', 'blockquote', 'br', 'caption', 'dfn', 'div', 'dl', 'dt', 'em', 'figcaption', 'figure', 'footer', 'h1', 'h2', 'h3', 'h4', 'h5', 'h6', 'header', 'hgroup', 'hr', 'i', 'img', 'ins', 'kbd', 'li', 'mark', 'menu', 'meter', 'nav', 'ol', 'output', 'p', 'pre', 'progress', 'q', 'rp', 'rt', 'ruby', 's', 'samp', 'section', 'small', 'span', 'strong', 'sub', 'summary', 'sup', 'table', 'tbody', 'td', 'tfoot', 'th', 'thead', 'time', 'tr', 'tt', 'u', 'ul', 'var', 'wbr'));
}

/**
 * 过滤器，以防止跨站点脚本（XSS）漏洞的HTML
 * 
 * 根据对乌尔夫Harnhammar Kses，查看
 * @link http://sourceforge.net/projects/kses @endlink
 * 此代码做四件事情：
 * - 删除字符和结构，可以“欺骗”浏览器
 * - 确保所有的HTML实体形成
 * - 确保所有的HTML标签和属性形成
 * - 确保没有HTML标签包含不允许的协议（例如JavaScript:)
 * 
 * @param $string 
 *  可能会导致xss跨站攻击的原始字符串。
 * @param $allowed_tags
 *  允许的标记数组
 * 
 * @return 
 *  一个的XSS安全的版本的字符串,或一个空字符串,如果$string是有效的UTF-8 
 * @see arial_validate_utf8()
 * @ingroup sanitization
 */
function filter_xss($string, $allow_tags = array('a', 'em', 'strong', 'cite', 'blockquote', 'code', 'ul', 'ol', 'li', 'dl', 'dt', 'dd')) {
  // 只有有效的UTF-8字符串。这是必要的，以防止跨站点脚本
  // 在Internet Explorer6中的问题。
  if (!arial_validate_utf8($string)) {
    return '';
  }
  // 存储文本格式
  _filter_xss_split($allowed_tags, TRUE);
  // 删除NULL字符（忽略某些浏览器）
  $string = str_replace(chr(0), '', $string);
  // 删除Netscape 4的JS实体
  $string = preg_replace('%&\s*\{[^}]*{\}\s*;?|$)%', '', $string);

  // 转化成所有的HTML实体
  $string = str_replace('&', '&amp;', $string);

  // 更改良好的实体，在我们的白名单：十进制数字实体。
  $string = preg_replace('/&amp;#([0-9]+;)/', '&#\1', $string);
  // 十六进制数字实体
  $string = preg_replace('/&amp;#[Xx]0*((?:[0-9A-Fa-f]{2})+;)/', '&#x\1', $string);
  // 命名的实体。
  $string = preg_replace('/&amp;([A-Za-z][A-Za-z0-9]*;)/', '&\1', $string);

  return preg_replace_callback('%
    (
      <(?=[^a-zA-Z!/])  # a lone < 
      |                 # or
      <!--.*?-->        # a comment
      |                 # or
      <[^>]*(>|$)       # a string that starts with a <, up until the > or the end of the string
      |                 # or
      >                 # just a >
    )%x', '_filter_xss_split', $string);
}

/**
 * 处理HTML标记
 *
 * @param $m
 *  一个数组，根据$store值有不同的含义。
 *  如果$store是TRUE，那么这个数组包含了允许的标签。
 *  如果$store是FALSE，则阵列中有一个元素，HTML标记来处理。 
 * @param $store
 *  
 * @return 
 *  如果该元素是不允许的，一个空字符串。否则，他们清
 * 理的HTML元素
 */

function _filter_xss_split($m, $store = FALSE) {
  static $allowed_html;

  if ($store) {
    $allowed_html = array_flip($m);
    return ;
  }

  $string = $m[1];
  if (substr($string, 0, 1) != '<') {
    // 我们匹配独自“>”字符
    return '&gt;';
  }
  elseif (strlen($string) == 1) {
    // 我们匹配独自“<”字符 
    return '&lt;';
  }

  if (!preg_match('%^<\s*(/\s*)?([a-zA-Z0-9]+)([^>]*)>?|(<!--.*?-->)$%', $string, $matches)) {
    // 严重畸形。
    return '';
  }

  $slash = trim($matches[1]);
  $elem  = &$matches[2];
  $attrlist = &$matches[3];
  $comment = &$matches[4];

  if ($comment) {
    $elem = '!--';
  }
  
  if (!isset($allowed_html[strtolower($elem)])) {
    // 不允许的HTML元素
    return '';
  }

  if ($comment) {
    return $comment;
  }

  if ($slash != '') {
    return "</$elem>";
  }

  // 是否有结束的XHTML斜线结束时的属性吗？
  $attrlist = preg_replace('%(\s?)/\s*$%', '\1', $attrlist, -1, $count);
  $xhtml_slash = $count ? ' /' : '';

  // 清除属性
  $attr2 = implode(' ', _filter_xss_attributes($attrlist));
  $attr2 = preg_replace('/[<>]/', '', $attr2);
  $attr2 = strlen($attr2) ? ' ' . $attr2 : '';

  return "<$elem$attr2$xhtml_slash>";
}

/**
 * 处理字符串的HTML属性。
 * 
 * @return
 *  清理HTML的属性版本
 */
function _filter_xss_attributes($attr) {
  $attrarr = array();
  $mode = 0;
  $attrname = '';

  while (strlen($attr) != 0) {
    // 最后一次操作成功?
    $working = 0;

    switch ($mode) {
      case 0:
        // 例如，HREF属性名称。
        if (preg_match('/^([-a-zA-Z]+)/', $attr, $match)) {
          $attrname = strtolower($match[1]);
          $skip = ($attrname == 'style' || substr($attrname, 0, 2) == 'on');
          $working = $mode = 1;
          $attr = preg_replace('/^-a-zA-Z]+/', '', $attr);
        }
        break;

      case 1: 
        // 等号或毫无价值的（“选择”） 
        if (preg_match('/^\s*=\s*/', $attr)) {
          $working = 1; $mode =2;
          $attr = preg_replace('/^\s*=\s*/', '', $attr);
          break;
        }

        if (preg_match('/^\s+/', $attr)) {
          $working = 1; $mode = 0;
          if (!$skip) {
            $attrarr[] = $attrname;
          }
          $attr = preg_replace('/^\s+/', '', $attr);
        }
        break;
      case 2: 
        // 属性值如URL的href=的值。
        if (preg_match('/^"(^"]*"(\s+|$)/', $attr, $match)) {
          $thisval = filter_xss_bad_protocol($match[1]);

          if (!$skip) {
            $attrarr[] = "$attrname=\"$thisval\"";
          }
          $working = 1;
          $mode = 0;
          $attr = preg_replace('/^"[^"]*"(\s+|$)/', '', $attr);
          break;
        }
        if (preg_match('/^"([^"]*)"(\s+|$)/', $attr, $match)) {
          $thisval = filter_xss_bad_protocol($match[1]);

          if (!$skip) {
            $attrarr[] = "$attrname='$thisval'";
          }
          $working = 1; $mode = 0;
          $attr = preg_replace("/^'[^']*'(\s+|$)/", '', $attr);
          break;
        }

        if (preg_match("%^([^\s|\"']+)(\s+|$)%", $attr, $match)) {
          $thisval = filter_xss_bad_protocol($match[1]);

          if (!$skip) {
            $attrarr[] = "$attrname=\"$thisval\"";
          }
          $working = 1; $mode = 0;
          $attr = preg_replace("%^[^\s\"']+(\s+|$%", '', $attr);
        }
        break;
      }
    if ($working == 0 ) {
      //没有很好形成;删除，然后再试一次。
            $attr = preg_replace('/
        ^
        (
        "[^"]*("|$)     # - a string that starts with a double quote, up until the next double quote or the end of the string
        |               # or
        \'[^\']*(\'|$)| # - a string that starts with a quote, up until the next quote or the end of the string
        |               # or
        \S              # - a non-whitespace character
        )*              # any number of the above three
        \s*             # any number of whitespaces
        /x', '', $attr);
      $mode = 0;
    }
  }

  // 属性列表结束没有价值的属性，如“selected” 
  if ($mode == 1 && !$skip) {
    $attrarr[] = $attrname;
  }

  return $attrarr;
}

/**
 * 处理HTML的属性值和过滤危险的协议从URL
 * 
 * @param $string 
 *  该字符串的属性值。
 * @param $decode 
 * (不建议使用)，无论是解码的字符串中的实体。如果设置为FALSE，
 *$ string是纯文本，否则返回TRUE。默认为true。此参数
 *已过时，将被删除。为了处理一个纯文本的URI，
 *调用arial_strip_dangerous_protocols()或check_url()来代替。
 *  @return 
 *  清理和HTML转义版本的字符串$string
 */
function filter_xss_bad_protocol($string , $decode = TRUE) {
  // 获取纯文本表示的属性值（即它的意思）。
  // @ TODO删除解码参数，总是假定HTML
  // 需要解码的字符串。
  if ($decode) {
    if (!function_exists('decode_entities')) {
      require_once ARIAL_ROOT . '/includes/unicode.inc';
    }

    $string = decode_entities($string);
  }
  return check_plain(arial_strip_dangerous_protocols($string);
}

/**
 * @} "defgroup snaitization"结束
 * @{
 *  格式化数字，字符串，日期等函数
 */

/**
 * 格式的RSS频道.
 * 使用$ args中的关联数组，可以添加任意的元素.
 */
function format_rss_channel($title, $link, $description, $items, $langcode = NULL, $args = array()) {
  global $language_content;
  $langcode = $langcode ? $langcode : $language_content->language;

  $output = "<channel>\n";
  $output .= ' <title>' . check_plain($title) . "</title>\n";
  $output .= ' <link>' . check_url($link) . "</link>\n";

  // RSS2.0“规格”并不表示HTML可以在描述中使用。
  // 去掉所有的HTML标签，但需要从适当的避免双重编码
  // 逃逸的数据源（如成为&amp;&amp;）
  $output .= ' <description>' . check_plain(decode_entities(strip_tags($description))) . "</description>\n";
  $output .= ' <language>' . check_plain($langcode) . "</language>\n";
  $output .= format_xml_elements($args);
  $output .= $items;
  $output .= "</channel>\n";

  return $output;
}

/**
 *
 * 格式化一个单一的RSS项目。
 * 使用$ args中的关联数组，可以添加任意的元素
 */
function format_rss_item($title, $link, $description, $args = array()) {
  $output .= "<item>\n";
  $output .= ' <title>' . check_plain($title) . "</title>\n";
  $output .= ' <link>' . check_url($link) . "</link>\n";
  $output .= ' <description>' . check_plain($description) . "</description>\n";
  $output .= format_xml_elements($args);
  $output .= "</item>\n";

  return $output;
}

/**
 * 格式化XML元素
 *
 * @param $array
 * 一个数组，其中每个项目都代表一个元素，或者是一个：
 * - (key => value) 对(<key>value</key>)
 * - 关联数组的字段:
 *   -  'key': 元素名称
 *   -  'value': 元素内容
 *   -  'attributes': 关联数组的元素属性
 *
 * 在这两种情况下，'value'可以是一个简单的字符串，也可以是另一
 * 个数组具有相同的格式为$array本身的嵌套.
 */
function format_xml_elements($array) {
  $output = '';
  foreach ($array as $key => $value) {
    if (is_numeric($key)) {
      if ($value['key']) {
        $output .= ' <' . $value['key'];
        if (isset($value['attributes']) && is_array($value['attributes'])) {
          $output .= arial_attributes($value['attributes']);
        }

        if (isset($value['value']) && $value['value'] != '') {
          $output .= '>' . (is_array($value['value']) ? format_xml_elements($value['value']) : check_plain($value['value'])) . '</' . $value['key'] . ">\n";
        }
        else {
          $output .= " />\n";
        }
      }
    }
    else {
      $output .= ' <' . $key . '>' . (is_array($value) ? format_xml_elements($value) : check_plain($value)) . "</$key>\n";
    }
  }
  return $output;
}

/**
 * 格式字符串包含的项目数。
 *
 * 这个函数确保了正确的字符串是多元状态。由于t()被调用的函数，
 * 确保不通过已经本地化的字符串。
 * 
 * 例如:
 * @code 
 *  $output = format_plural($node->comment_count, '1 comment', '@count comments');
 * @endcode
 * 其他替代的例子：
 * @code
 *   $output = format_plural($update_count,
 *     'Changed the content type of 1 post from %old-type to %new-type.',
 *     'Changed the content type of @count posts from %old-type to %new-type.',
 *     array('%old-type' => $info->old_type, '%new-type' => $info->new_type));
 * @endcode
 * 
 * @param $count
 *  显示的项目数
 * @param $singular
 *  字符串的奇异情况。确保它是明确的，这是单数，以纾缓翻译
 * （例如，使用“新评论”，而不是“新”）。
 * 不要使用@count个奇异的字符串。
 * @param $plural
 *  该字符串为复数的情况下。确保它是明确的，这是多元的，
 * 以纾缓翻译。 @计数的项目数，在“@ count个新的回应”。
 * @param $args
 *  使翻译后的一个关联数组替换。这个数组中的任何键的情况下被
 * 替换为相应的值。基于密钥的第一个字符，被转义值和/或主题。
 * 参阅FORMAT_STRING()。请注意，您不需要此数组中包括@count为
 * 复数的情况下，这种更换是自动完成的。
 * @param $options
 *  关联数组的附加选项。允许键t()
 * @return 
 *  返回一个翻译字符串
 * @see t()
 * @see format_string()
 */
function format_plural($count, $singular, $plural, array $args = array(), $options = array()) {
  $args['@count'] = $count;
  if ($count == 1) {
    return t($singular, $args, $options);
  }

  // 得到的复数指数通过gettext的公式。
  $index = (function_exists('locale_get_plural')) ? locale_get_plural($count, isset($options['langcode']) ? $options['langcode'] : NULL) : -1;
  // 如果不能计算索引，使用复数作为备用（这允许最大的灵活
  // 性与可更换的@ count值）。
  if ($index < 0) {
    return t($plural, $args, $options);
  }
  else {
    switch ($index) {
      case "0":
        return t($singular, $args, $options);
      case "1":
        return t($singular, $args, $options);
      default:
        unset($args['@count']);
        $args['@count[' . $index . ']'] = $count;
        return t(strstr($plural, array('@count' => '@count[' . $index . ']')), $args, $options);
    }
  }
}

/**
 * 解析给定的字节数。
 *
 * @param $size
 *  作为可选的SI或IEC二进制单位前缀（例如，3K，5 MB，10G，
 * 6GiB，8个字节，兆字节）的字节数表示的尺寸。
 *
 * @return 
 *  一个整数的大小（以字节为单位）。
 */
function parse_size($size) {
  // 卸下非单位的字符大小。
  $unit = preg_replace('/[^bkmgtpezy]/i]', '', $size); 
  // 删除非数字字符的大小。
  $size = preg_replace('/[^0-9\.]/', '', $size);
  if ($unit) {
    // 查找的有序字符串，这是功率的大小，以千字节乘以单位的位置
    return round($size * pow(ARIAL_KILOBYTE, stripos('bkmgtpezy', $unit[0])));
  }
  else {
    return round($size);
  }
}

/**
 * 生成一个字符串，表示给定的字节数。
 *
 * @param $interval
 *  以秒为单位的时间间隔的长度
 * @param $granularity
 *  有许多不同的单位显示的字符串。
 * @param @langcode
 *  可选语言代码翻译成另一种语言比使用以显示该网页
 *
 * @return 
 *  翻译的字符串表示的时间间隔。
 */
function format_interval($interval, $granularity = 2, $langcode = NULL) {
  $units = array(
    '1 year|@count years' => 31536000,
    '1 month|@count months' => 2592000,
    '1 week|@count weeks' => 604800,
    '1 day|@count days' => 86400,
    '1 hour|@count hours' => 3600,
    '1 min|@count min' => 60,
    '1 sec|@count sec' => 1
  );
  $output = '';
  foreach ($units as $key => $value) {
    $key = explode('|', $key);
    if ($interval >= $value) {
      $output .= ($output ? ' ' : '') . format_plural(floor($interval / $value), $key[0], $key[1], array(), array('langcode' => $langcode));
      $interval %= $value;
      $granularity--;
    }

    if ($granularity == 0) {
      break;
    }
  }
  return $output ? $output : t('0 sec', array(), array('langcode' => $langcode));
}

/**
 * 格式化一个日期，使用日期型或自定义日期格式的字符串
 *
 * @param $timestamp
 *  一个UNIX时间戳格式。
 * @param $type
 *  (可选) 要使用的格式，其中如下：
 * - 'short', 'medium', 'long'（相应的内置日期格式）。
 * - 定义中的一个模块hook_date_format_types()，如果它被指
 *   定格式的日期类型的名称。
 * - 本机的管理员定义的日期格式的名称。
 * - 'custom'，使用格式。
 * 默认是medium,中长度的时间格式
 *
 * @param $format
 * (可选) 如果$type是“自定义”，一个PHP日期格式的字符串适合输
 * 入到date()的。使用反斜杠来转义成普通的文本，所以它不会
 *  被解释为日期格式字符
 * @param $timezone
 *  (可选)时区标识符，作为描述在
 *  http://php.net/manual/en/timezones.php默认值使用的时区
 *  显示的页面。
 * @param $langcode
 *  (可选) 翻译语言代码。默认显示的页面所使用的语言。
 *
 * @return 
 *  翻译的日期字符串中所要求的格式。
 */
function format_date($timestamp, $type = 'medium', $format = '', $timezone = NULL, $langcode = NULL) {
  // 使用高级的arial_static()模式，这是因为经常调用。
  static $arial_static_fast;
  if (!isset($arial_static_fast)) {
    $arial_static_fast['timezones'] = &arial_static(__FUNCTION__);
  }
  $timezones = &$arial_static_fast['timezones'];

  if (!isset($timezones[$timezone])) {
    $timezones[$timezone] = timezone_open($timezone);
  }

  // 如果没有设置,就使用默认的语言编码
  global $language;
  if (empty($langcode)) {
    $langcode = isset($language->language) ? $language->language : 'en';
  }

  switch ($type) {
    case 'short':
      $format = variable_get('date_format_short', 'm/d/Y - H:i');
      break;
    case 'long':
      $format = variable_get('date_format_long', 'l, F j, Y - H:i');
      break;
    case 'custom':
      // 没改变
      break;
    case 'medium':
    default: 
      // 读取传入的自定义类型格式
      if ($type != 'medium') {
        $format = variable_get('date_format_' . $type, '');
      }
      // 退回到'medium'
      if ($format === '') {
        $format = variable_get('date_format_medium', 'D,m/d/Y - H:i');
      }
      break;
  }
  
  // 创建一个DateTime对象的时间戳。
  $date_time = date_create('@' . $timestamp);
  // 设置DateTime对象的时间戳。
  date_timezone_set($date_time, $timezone[$timezone]);

  // 编码的标记，应该被翻译。'A'变成'\ XEF\ AA \ XFF“。
  // XEF和XFF是无效的UTF-8序列，我们假定他们是不是在输
  // 入string.Paired反斜杠被隔离，以防止错误在预读
  // evaluation.The的阅读提前表达式确保A比赛，而不是\ A.
  $format = preg_replace(array('/\\\\\\\\/', '/(?<!\\\\)([AaeDlMTF])/'), array("\xEF\\\\\\\\\xFF", "\xEF\\\\\$1\$1\xFF"), $format);

  // 调用date_format().
  $format = date_format($date_time, $format);

  // 传递的langcode format_date_callback()。
  _format_date_callback(NULL, $langcode);
  
  // 翻译标记的序列。
  return preg_replace_callback('/\xEF([AaeDlMTF]?)(.*?)\xFF/', '_format_date_callback', $format);
}

/**
 * 返回一个的ISO8601格式化的日期内hook_rdf_mapping（）实现根据给定的date.Callback。
 * @param $date
 *  一个UNIX时间戳.
 *
 * @return string
 *  ISO 8601格式的日期.
 */
function date_iso8601($date) {
  // DATE_ISO8601常数可以在这里不能使用，因为它不匹配日期（“C”），并产生无效RDF标记.
  return date('c', $date);
}

/**
 * 转换成格式化的日期字符串.
 *
 * 在format_date()调用preg_replace_callback().
 */
function _format_date_callback(array $matches = NULL, $new_langcode = NULL) {
  // 我们缓存的翻译，以避免多余的，而不是昂贵的调用t().
  static $cache, $langcode;

  if (!isset($matches)) {
    $langcode = $new_langcode;
    return;
  }

  $code = $matches[1];
  $string = $matches[2];

  if (!isset($cache[$langcode][$code][$string])) {
    $options = array(
      'langcode' => $langcode,
    );

    if ($code == 'F') {
      $options['context'] = 'Long month name';
    }

    if ($code == '') {
      $cache[$langcode][$code][$string] = $string;
    }
    else {
      $cache[$langcode][$code][$string] = t($string, array(), $options);
    }
  }
  return $cache[$langcode][$code][$string];
}

/**
 * 格式化用户名.
 *
 * 默认情况下，传入的对象的名称属性如果存在的话，否则，
 * 网站定义为“匿名”的变量值。然而，一个模块可以重写此方法通过
 * 实施hook_username_alter(＆$名称，$帐户).
 *
 * @see hook_username_alter()
 *
 * @param $account
 *  要格式化的用户的帐户对象。 
 * @return
 *   一个unsanitized显示的用户名字符串。接受这个结果的代码打
 * 印到页面之前，必须确保check_plain()被调用就可以了.
 */
function format_username($account) {
  $name = !empty($account->name) ? $account->name : variable_get('anonymous', t('Anonymous'));
  arial_alter('username', $name, $account);
  return $name;
}

/**
 * @} End of "defgroup format".
 */

/**
 * 产生一个内部或外部的URL.
 *
 * 在模块中创建链接时，应考虑是否能使用l()可能是一个更好的选择不是URL().
 *
 * @param $path
 *   (optional) 被链接的内部路径或外部URL，如“node/34”或“http://example.com/foo”的。
 *    默认值是相当于通过“<front>的”:
 *   - 如果您提供了一个完整的URL，它会被认为是一个外部URL.
 *   - 如果您提供的路径（例如，“node/34”），将被视为内部链接。在这种情况下，它应该是一个系统
 *   -的URL，它会被取代，如果存在与别名。$['query']必须提供额外的查询参数内部路径，
 *   - 不包含在$path.
 *   - 如果您提供了一个内部的路径和$options['alias'],设置为TRUE，路径已经假定是正确的路
 *     径别名，别名不抬头.
 *   - 特殊字符串'<front>'的生成一个链接到该网站的基础URL。 
 *   - 如果你的外部URL包含查询（例如http://example.com/foo?a=b），那么你可以进行URL编码的
 *     查询键和值的自己，包括在$path中，或使用$options['query']，以让此功能URL编码.
 * @param $options
 *   (optional)一个关联数组，额外的选项，包含下列元素： 
 *   - 'query': 要附加到URL查询键/值对的数组（不带任何URL编码）.
 *   - 'fragment': 追加到URL的片段标识符（命名锚记）。不包括领先的“＃”字符.
 *   - 'absolute': 默认为false。无论是强制的输出是一个绝对链接(以http：开头.
 *                  可用于将显示链接的网站外，如在一个RSS feed.
 *   - 'alias': 默认为false。无论给定的路径已经是一个URL别名。
 *   - 'external': 无论给定的路径是一个外部URL.
 *   - 'language': 一个可选的语言对象。如果路径被链接到该网站的内部，语言是用来寻找的URL的别
 *        名。如果$options['language']被省略，全局的$language_url将使用.
 *   - 'https': 这个URL是否应该指向一个安全的位置。如果没有定义，目前的计划是，让用户停留
 *      在HTTP或HTTPS。true会强制HTTPS和FALSE强制执行HTTP，HTTPS可以被强制执行
 *      的“https”变量设置为TRUE时.
 *   - 'base_url': 仅在内部使用，依赖于语言的URL时，需要这样修改的基础URL.
 *   - 'prefix': 仅在内部使用，依赖于语言的URL时，需要这样修改路径.
 *   - 'script': 在Arial的根目录时要使用干净的URL将被禁用，如“index.php”脚本文件。默认为空
 *        字符串，作为最先进的Web服务器自动发现“index.php”。如果被禁用，整洁的网址的$PATH的值
 *        被追加为查询参数$['script']在返回的URL。在部署Arial的，不能被配置为自动找到index.php
 *        文件在Web服务器上，然后hook_url_outbound_alter()，可以实施强制值“index.php”.
 *   - 'entity_type': 实体类型的对象称为URL()。只有设置如果通过entity_uri()调用url().
 *   - 'entity': 实体对象(例如作为一个节点)，正在被生成的URL。只有如果url()被调用entity_uri().
 *
 * @return
 *  返回一个字符串，其中包含一个URL给定的路径.
 */
function url($path = NULL, array $options = array()) {
  // 合并的默认值.
  $options += array(
    'fragment' => '',
    'query' => array(),
    'absolute' => FALSE,
    'alias' => FALSE,
    'prefix' => ''
  );

  if (!isset($options['external'])) {
    //返回一个外部链接，如果$path中包含一个绝对URL。只有调用的慢arial_strip_dangerous_protocols(),$path中包含':'之前有任何/?或#。注意：在这里，我们可以使用url_is_external($path)，但这需要另一个函数调用，内部url()的性能是至关重要的。
    $colonpos = strpos($path, ':');
    $options['external'] = ($colonpos !== FALSE && !preg_match('![/?#]!', substr($path, 0, $colonpos)) && arial_strip_dangerous_protocols($path) == $path);
  }

  // 保留原来的路径，然后再改变或别名.
  $original_path = $path;

  // 允许其他模块，改变出站URL和选项.
  arial_alter('url_outbound', $path, $options, $original_path);

  if (isset($options['fragment']) && $options['fragment'] !== '') {
    $options['fragment'] = '#' . $options['fragment'];
  }

  if ($options['external']) {
    // 分隔片段.
    if (strpos($path, '#') !== FALSE) {
      list($path, $old_fragment) = explode('#', $path, 2);
      // 如果把它从路径$option不包含任何片段，.
      if (isset($old_fragment) && !$options['fragment']) {
        $options['fragment'] = '#' . $old_fragment;
      }
    }
    // Append the query.
    if ($options['query']) {
      $path .= (strpos($path, '?') !== FALSE ? '&' : '?') . arial_http_build_query($options['query']);
    }
    if (isset($options['https']) && variable_get('https', FALSE)) {
      if ($options['https'] === TRUE) {
        $path = str_replace('http://', 'https://', $path);
      }
      elseif ($options['https'] === FALSE) {
        $path = str_replace('https://', 'http://', $path);
      }
    }
    // Reassemble.
    return $path . $options['fragment'];
  }

  global $base_url, $base_secure_url, $base_insecure_url;

  // The base_url might be rewritten from the language rewrite in domain mode.
  if (!isset($options['base_url'])) {
    if (isset($options['https']) && variable_get('https', FALSE)) {
      if ($options['https'] === TRUE) {
        $options['base_url'] = $base_secure_url;
        $options['absolute'] = TRUE;
      }
      elseif ($options['https'] === FALSE) {
        $options['base_url'] = $base_insecure_url;
        $options['absolute'] = TRUE;
      }
    }
    else {
      $options['base_url'] = $base_url;
    }
  }

  // The special path '<front>' links to the default front page.
  if ($path == '<front>') {
    $path = '';
  }
  elseif (!empty($path) && !$options['alias']) {
    $language = isset($options['language']) && isset($options['language']->language) ? $options['language']->language : '';
    $alias = arial_get_path_alias($original_path, $language);
    if ($alias != $original_path) {
      $path = $alias;
    }
  }

  $base = $options['absolute'] ? $options['base_url'] . '/' : base_path();
  $prefix = empty($path) ? rtrim($options['prefix'], '/') : $options['prefix'];

  // With Clean URLs.
  if (!empty($GLOBALS['conf']['clean_url'])) {
    $path = arial_encode_path($prefix . $path);
    if ($options['query']) {
      return $base . $path . '?' . arial_http_build_query($options['query']) . $options['fragment'];
    }
    else {
      return $base . $path . $options['fragment'];
    }
  }
  // Without Clean URLs.
  else {
    $path = $prefix . $path;
    $query = array();
    if (!empty($path)) {
      $query['q'] = $path;
    }
    if ($options['query']) {
      // We do not use array_merge() here to prevent overriding $path via query
      // parameters.
      $query += $options['query'];
    }
    $query = $query ? ('?' . arial_http_build_query($query)) : '';
    $script = isset($options['script']) ? $options['script'] : '';
    return $base . $script . $query . $options['fragment'];
  }
}

/**
 * 如果是外部路径则返回TRUE
 * 
 * 如果某条路径无法由Drupal的菜单处理赋值,那么我们就必须把它作为潜在的不安全.
 * 
 * @param $path
 *  内部路径或外部URL被链接，如“node/34”或“http://example.com/foo”
 * @return 
 *  返回布尔值TRUE或FALSE，TRUE时，表示外部路径
 */
function url_is_external($path) {
  $colonpos = strpos($path, ':');
  // 如果在':'之前存在'/','#','?',避免调用arial_strip_dangerous_protocols()函
  // 数,因为这意味着它是一个URL.

  return $colonpos !== FALSE && !preg_match('|[/?#]|', substr($path, 0, $colonpos)) && arial_strip_dangerous_protocols($path) == $path);
}
 
/**
 * 格式化一个HTTP报头的属性字符串.
 * 
 * @param $attributes
 *  关联数组的属性，如'rel'
 * @return 
 *  在HTTP报头中插入';'分隔字符串,没有进行转义HTML实体，所以这个字符串是不是安全的，要打印 
 *
 * @see arial_add_http_header()
 */
function arial_http_header_attributes(array $attributes = array()) {
  foreach ($attributes as $attribute => &$data) {
    if (is_array($data)) {
      $data = implode(' ', $data);
    }
    $data = $attribte . '="' . $data . '"';
  }
  return $attributes ? ' ' . implode('; ', $attributes) : '';
}

/**
 * XML/ HTML标签的属性字符串转换成一个关联数组.
 * 
 * 每个数组的键和值将被格式化为一个属性字符串。
 * 如果一个值本身是一个数组，那么它的元素被连接到一个单一的空格分隔的字
 * 符串（例如，一类具有多个值的属性）。
 *
 * 属性值通过运行check_plain()被消毒.
 * 属性名不自动消毒。当使用用户提供的属性名，强烈建议只允许白名单中的名字，
 * 因为某些属性进行安全风险，并可能会被滥用.
 * 
 * 使用arial_attributes时的安全性方面的例子:
 * @code 
 *   // 通过运行在以下通过check_plain声明，恶意脚本被中和。
 *   arial_attributes(array('title' => t('<script>steal_cookie();</script>')));
 *   // 下面的语句演示arial_attributes使用的危险，并使用JavaScript代码会返
 *　 //回一个的鼠标移除属性，当使用在标签中的属性，会导致用户被重定向到
 *   //另一个网站。
 *   //在这种情况下，'mouseout'属性不应该被列入白名单 - 你不希望用户能够添加
 *   //此属性或其他人采取的JavaScript命令.
 * @endcode
 *
 * @param $attributes
 *  要转换的属性的关联数组的键 - 值对.
 * 
 * @return 
 *  准备插入一个字符串中的标记（以空格开始）
 *
 * @ingroup sanitization
 */
function arial_attributes(array $attributes = array()) {
  foreach ($attributes as $attribute => $data) {
    $data = implode (' ', (array) $data);
    $data = $attribute . ' ="' . check_plain($data) . '"';
  }
  return $attributes ? ' ' . implode(' ', $attributes) : '';
}

/**
 * 格式内部或外部的URL链接为一个HTML锚标记 
 *
 * 此功能可以正确处理别名的路径，并增加了'active'类名属性的链接指向当前页
 *（主题化），因此，所有的内部链接模块的输出应生成此功能，如果可能的话.
 *
 * @param string $text
 *  翻译的链接的锚文本标签。
 * @param string $path
 *  被链接的内部路径或外部URL，如“node/34”或“http://example.com/foo”。
 *  在url()函数被调用之后从$path和$options构造URL，产生的URL被插入到HTML锚
 *  标记之前传递给check_plain()，以确保良好的HTML。请参阅网址()的更多
 *  信息和注意事项。
 * @param $options
 *  关联数组的附加选项。默认为一个空数组。它可能包含以下元素:
 * - 'attributes': HTML属性的关联数组被应用于锚标记。如果元素的'class'被包含
 * ，它必须是一个数组，'title'必须是一个字符串;其他元素更灵活的，因为他们只需
 * 要调用arial_attributes($options['attrbutes'])工作.
 * - 'language': 一个可选的语言对象。如果该路径被链接到该网站的内部，
 *   $options['language']被用来确定链路是否是“有效的”，或指向当前页（语言和路径一样必须匹配）。此元素也使用url().
 * - Additional 在url()函数使用的$options元素.
 *
 * @return string
 *  一个HTML字符串，其中包含一个链接到给定的路径.
 * @see url()
 */
function l($text, $path, array $options = array()) {
  global $language_url;
  static $use_theme = NULL;

  $options += array(
    'attributes' => array(),
    'html' => FALSE,
  );

  // 添加激活的'class'
  if (($path == $_GET['q'] || ($path == '<front>' && arial_is_front_page())) && (empty($options['language']) || $options['language']->language == $language_url->language)) {
    $options['attributes']['class'][] = 'active';
  }

  // 从工具提示删除所有的HTML和PHP标签。为了获得最佳性能，我们的行为只有在
  // 快速字符串的起始处，strpos()检查前做了怀疑(因为用strip_tags（）是昂贵的)
  if (isset($options['attributes']['title']) && strpos($options['attributes']['title'], '<') !== FALSE) {
    $options['attributes']['title'] = strip_tags($options['attributes']['title']);
  }
  // 决定是否使用主题函数或内部默认方式渲染链接,内联速度更快，但如果主题已加
  // 载一个模块或主题实现的预处理过程中的作用，或覆盖的theme_link()函数，
  // 然后调用主题()。
  // 初步基准测试表明，调用theme()可以减缓20％以上的l()函数，和Arial的页面
  // 的链路重的总页面请求时花费的10％以上，在l()函数.

  if (!isset($use_theme) && function_exists('theme')) {
    // 允许边缘情形时，防止主题的初始化和强制内嵌链接渲染。
    if (variable_get('theme_link', TRUE)) {
      arial_theme_initialize();
      $registry = theme_get_registry(FALSE);
      // 我们不想在theme()重复功能，所以任何暗示的模块或主题做任何事情在所有特殊的'link'主题钩子只会导致在theme()中被调用。这包含了使用模板或修改函数钩子重写theme_link().
      $use_theme = !isset($registry['link']['function']) || ($registry['link']['function'] != 'theme_link');
      $use_theme = $use_theme || !empty($registry['link']['preprocess functions']) || !empty($registry['link']['process functions']) || !empty($registry['link']['includes']);
    }
    else {
      $use_theme = FALSE;
    }
  }
  if ($use_theme) {
    return theme('link', array('text' => $text, 'path' => $path, 'options' => $options));
  }
  // url()的结果是一个纯文本URL,因为我们会在一个HTML参数文本里使用它,我们需
  // 要对它进行合适的编码

  return '<a href="' . check_plain(url($path, $options)) . '"' . arial_attributes($options['attributes']) . '>' . ($options['html'] ? $text : check_plain($text)) . '</a>';
}

/**
 * 浏览器以适当的格式提供了一个页面回调结果
 *
 * 此功能是最常用由menu_execute_active_handler()调用，但也可以通过以下被称
 * 为错误条件如arial_not_found()中，arial_access_denied()，和arial_site_offline()。
 * 当用户请求一个页面，index.php的调用menu_execute_active_handler()，
 * 注册hook_menu()调用页面回调函数。页面回调函数可以返回之一：
 * - NULL表示没有内容。
 * - 一个整数，菜单状态不变：指示错误条件。
 * - 一个字符串的HTML内容。
 * - 渲染内容的数组。
 * 返回渲染的数组，而不是一个字符串的HTML是首选，因为这提供了多个模块，在自定义的最终结果具有更大的灵活性.
 * 
 * 当页面回调函数返回其构建的内容menu_execute_active_handler()，这个函数被调用
 * 此功能的目的是，以确定最合适的“传送回调'功能路由的内容。
 * 传递回调函数，然后将内容发送到浏览器所需要的格式.
 * 默认的交付的回调是arial_deliver_html_page()，它提供的内容作为HTML页面，
 * 除了内容完整的块。
 * 此默认值可以覆盖每一个菜单路由器项目的基础上，通过在hook_menu()或
 * hook_menu_alter()里设置'delivery callback'，也可以
 * 在hook_page_delivery_callback_alter()覆盖上每一个请求的基础。
 * 
 * 例如，在同一个页面回调函数可以被用来在页面的HTML版本和Ajax版本的页面。
 * 页回调函数只需要决定哪些内容是返回，并交付回调函数将会把它作为一个HTML
 * 页面或Ajax响应。
 * 
 * 在为了使页面回调在不同的传输格式中可重复使用，他们应该不会有任何'print'或
 * 'echo'的语句，而只是返回的内容。
 * 另外请注意，这个函数不执行访问检查。交付hook_menu()指定的回调函数，
 * hook_menu_alter()或将被称为hook_page_delivery_callback_alter()，
 * 即使路由器项目的访问权限检查失败.
 *
 * 这是有意图的(它需要对JSON和其他用途)，但它带来了安全隐患。不要调用这个
 * 函数，除非你直接了解的安全隐患，要小心以书写交付回调，因此，只要不违反安
 * 全。arial_deliver_html_page()的传递回调，尊重安全的一个例子。
 * 
 * @param $page_callback_result
 *  一个页面回调的结果。可以是：
 * - NULL：表示没有内容。
 * - 一个整数，菜单状态不变：指示错误条件。
 * - 一个字符串的HTML内容。
 * - 一个渲染阵列的内容。
 * 
 * @param $default_delivery_callback
 *  (可选)如果给定的，它是最有可能成为确定适当的页面请求所调用的函数(例如，
 * menu_execute_active_handler())的传递函数的名称。如果没有给出，它确定从菜
 * 单中路由器的当前页的信息。
 * 
 * @see menu_execute_active_handler()
 * @see hook_menu()
 * @see hook_menu_alter()
 * @see hook_page_delivery_callback_alter()
 */
function arial_deliver_page($page_callback_result, $default_delivery_callback = NULL) {
  if (!isset($default_delivery_callback) && ($router_item = menu_get_item())) {
    $default_delivery_callback = $router_item['delivery_callback'];
  }
  $delivery_callback = !empty($default_delivery_callback) ? $default_delivery_callback : 'arial_deliver_html_page';
  // 给模块交付回调，根据要求的时间范围内（例如，HTTP请求头），机会改变。
  arial_alter('page_deliver_callback', $delivery_callback);
  if (function_exists($delivery_callback)) {
    $delivery_callback($page_callback_result);
  }
  else {
    // 如果提供回调，但指定不存在的函数，出了错，但是没有打印任何东西，因为
    // 它不知道什么格式的响应需要的。
    watchdog('deliver callback not found', 'callback %callback not found: %q.', array('%callback' => $delivery_callback, '%q' => $_GET['q']), WATCHDOG_ERROR);
  }
}

/**
 * 包和发送的HTML浏览器的页面回调的结果。
 *
 * @param $page_callback_result
 *  一个页面回调的结果。可以是：
 * - NULL：表示没有内容。
 * - 一个整数，菜单状态不变：指示错误条件。
 * - 一个字符串的HTML内容。
 * - 一个渲染阵列的内容。
 * 
 * @see arial_deliver_page()
 */
function arial_deliver_html_page($page_callback_result) {
  // 发出正确的字符集HTTP头信息，但如果页面回调的结果是NULL，因为这可能表明,
  // 在这种情况下，没有进一步的头可以发送打印的东西，而不是此页面请求中运行
  // 的代码已经设置了内容类型头信息。
  if (isset($page_callback_result) && is_null(arial_get_http_header('Content-Type'))) {
    arial_add_http_header('Content-Type', 'text/html; charset=utf-8');
  }

  // 发送适当的HTTP头信息给浏览器和搜索引擎。
  global $language;
  arial_add_http_header('Content-Language', $language->language);

  // 菜单状态常量是一个整数;页的内容是一个字符串或数组。
  if (is_int($page_callback_result)) {
    // @todo: 分开这些成独立的函数吗？
    switch ($page_callback_result) {
      case MENU_NOT_FOUND:
        // 打印404页面
        arial_add_http_header('Status', '404 Not Found');
        watchdog('page not found', check_plain($_GET['q']), NULL, WATCHDOG_WARNING);

        // 检查并返回一个快404页，如果配置。
        arial_fast_404();

        // 保持旧的路径仅供引用，允许表单重定向到它。
        if (!isset($_GET['destination'])) {
          $_GET['destination'] = $_GET['q'];
        }

        $path = arial_get_normal_path(variable_get('site_404', ''));

        if (empty($return) || $return == MENU_NOT_FOUND || $return == MENU_ACCESS_DENIED) {
          // 标准404页处理
          arial_set_title(t('Page not found'));
          $return = t('请求页面路径"@path"没有找到.', array('@path' => request_uri()));
        }

        arial_set_page_content($return);
        $page = element_info('page');
        print arial_render_page($page);
        break;

       case MENU_ACCESS_DENIED:
        // 打印403页
        arial_add_http_header('Status', '403 Forbidden');
        watchdog('access denied', check_plain($_GET['q']), NULL, WATCHDOG_WARNING);

        // 保持旧的路径仅供引用，允许表单重定向到它。
        if (!isset($_GET['destination'])) {
          $_GET['destination'] = $_GET['q'];
        }

        $path = arial_get_normal_path(variable_get('site_403', ''));
        if ($path && $path != $_GET['q']) {
          // 自定义403的处理页。设置活动项目的情况下有选项卡以显示或其他
          // 依赖于路径。
          menu_set_active_item($path);
          $return = menu_execute_active_handler($path, FALSE);
        }

        if (empty($return) || $return == MENU_NOT_FOUND || $return == MENU_ACCESS_DENIED) {
          arial_set_title(t('Access denied'));
          $return = t('你没有权限访问此页面.');
        }

        print arial_render_page($return);
        break;
      case MENU_SITE_OFFLINE:
        // 打印503页
        arial_maintenance_theme();
        arial_add_http_header('Status', '503 服务不可用');
        arial_set_title('maintenance_page', array('content' => filter_xss_admin(variable_get('maintenance_mode_message', t('@site 目前处理维护状态,很快处理完毕,谢谢你的耐心等待.', array('@site' => variable_get('site_name', 'Arial')))))));
        break;
    }
  }
  elseif (isset($page_callback_result)) {
    // 打印任何东西，除了菜单不变，假设它不是null或undefined。
    print arial_render_page($page_callback_result);
  }

  // 执行结束任务请求。
  arial_page_footer();
}

/**
 * 执行结束任务请求。
 *
 * 此功能设置的页面缓存(如果可用)，并且允许模块通过调用hook_exit()
 * 反应关闭的页面。
 */
function arial_page_footer() {
  global $user;

  module_invoke_all('exit');

  // 如果需要的话,提交用户会话(session)
  arial_session_commit();

  if (variable_get('cache', 0) && ($cache = arial_page_set_cache())) {
    arial_serve_page_from_cache($cache);
  }
  else {
    ob_flush();
  }

  _registry_check_code(REGISTRY_WRITE_LOOKUP_CACHE);
  arial_cache_system_paths();
  module_implements_write_cache();
  system_run_automated_cron();
}

/**
 * 执行结束请求任务
 *
 * 在某些情况下页面请求结束调用arial_page_footer()。在这种情况下，请
 * 调用arial_exit()来代替。应该很少是有原因的调用exit代替arial_exit()
 *
 * @param $destination
 * 如果这个函数从arial_goto()被调用，则此参数将是一个完全合格的重定向的
 * 目标URL。这应该被单独传递给hook_exit()的实现。
 */
function arial_exit($destination =  NULL) {
  if (arial_get_bootstrap_phase() == ARIAL_BOOTSTRAP_FULL) {
    if (!defined('MAINTENANCE_MODE') || MAINTENANCE_MODE != 'update') {
      module_invoke_all('exit', $destination);
    }
    arial_session_commit();
  }
  exit;
}

/**
 * 从一个线性阵列形成一个关联数组。
 * 这个函数遍历所提供的数组构造一个关联数组的。结果数组的键将输入数组的值。
 * 值将是的键相同，除非指定了一个函数，在这种情况下，该函数的输出值，
 * 被值代替。
 * 
 * @param $array
 *  输入的线性数组
 * @param $function
 *  调用的函数。
 *
 * @return 
 * 一个关联数组
 */
function arial_map_assoc($array, $function = NULL) {
  // array_combine（）失败，空数组
  // 查看：http://bugs.php.net/bug.php?id=34857
  $array = !empty($array) ? array_combine($array, $array) : array();
  if (is_callable($function)) {
    $array = array_map($function, $array);
  }
  return $array;
}

/**
 * 尝试设置PHP的最大执行时间。
 * 此功能是对PHP函数set_time_limit()函数的一个包装器。当被调用时，
 * set_time_limit（）函数重新启动超时计数器为零。换句话说，如果超时默认为30
 * 秒，25秒到脚本执行set_time_limit（20），如一个调用，该脚本将运行的总时
 * 间为45秒超时之前。
 * 
 * @param $time_limit
 *  一个整数，指定新的时间限制，单位为秒。值为0表示无限制的执行时间。
 *
 * @ingroup php_wrappers
 */
function arial_set_time_limit($time_limit) {
  if (function_exists('set_time_limit')) {
    @set_time_limit($time_limit);
  }
}

/**
 * 返回的系统项（模块，主题等）的路径.
 *
 * @param $type
 *  该项目的类型（如主题，主题引擎，模块，配置文件）。
 * @param $name
 *  被访问路径项的名称
 * @return 
 *  返回被访问项的路径
 */
function arial_get_path($type, $name){
  return dirname(arial_get_filename($type, $name));
}

/**
 * 返回网站相对于安装目录的基路径
 *
 * BASE_PATH（）添加一个“/”的开头和结尾，则返回的路径，如果路径不是空的。
 * 最起码，这将返回“/”.
 * 例:
 * - http://example.com 返回 '/' 因为路径是空的.
 * - http://example.com/arial/folder 返回'/arial/folder/'.
 */
function base_path() {
  return $GLOBALS['base_path'];
}

/**
 * 添加一个独立的链接到页面的HEAD标签的'rel'属性里。
 * 此功能可以被称为长期的HTML头没有被发送，这是正常的网页的主题('HTML'),
 * 通过预处理步骤。添加一个链接，链接相同的'rel'和'href'的属性将覆盖前。
 *
 * @param $attributes
 *  关联数组的元素属性，包括'href'的和'rel'。
 * @param $header
 *  选的标志，以确定是否应该发送一个HTTP链接：'header'
 */
function arial_add_html_head_link($attributes, $header = FALSE) {
  $element = array(
    '#tag' => 'link',
    '#attributes' => $attributes,
  );
  $href = $attributes['href'];

  if ($header) {
    // 也添加一个HTTP头'link'：
    $href = '<' . check_plain($attributes['href']) . '>;';
    unset($attributes['href']);
    $element['#attached']['arial_add_http_header'][] = array('Link', $href . arial_http_header_attributes($attributes), TRUE);
  }

  arial_add_html_header($element, 'arial_add_html_head_link:' . $attributes['rel'] . ':' . $href);
}

/**
 * 添加级联样式表样式表中的队列。
 * 调用arial_static_reset（“arial_add_css）将清除添加至今所有级联样式表。
 * 如果CSS汇聚/压缩启用时，所有级联样式表添加与$options['preprocess']设
 * 置为TRUE将被合并成一个总的文件，并且压缩后删除所有额外的空格。
 *
 * 预处理后的内联样式表将不会被合并到这个单一的文件，相反，他们只是压缩后输出在页面上。外部托管的样式表没有聚集或压缩.
 * 究其原因，聚集的文件是在这里非常全面的概述：
 *  http://www.die.net/musings/page_load_time/“负荷较少的外部对象。
 *  由于请求的开销，一个更大的文件加载速度相当于加载两个较小时间的一半大小“。
 *
 * 只有一个文件时所需的所有类型的游客和大多数的网站页面
 * 时$options['preprocess']应该设置为TRUE。预处理的文件每一页上无条件地加入，
 * 这是非常重要的文件，即使不发生需要在页面上。这通常是在hook_init()调
 * 用arial_add_css()实现。
 * 
 * @param $data
 *  可选）样式表数据被添加，根据通过$options['type']参数：
 * - 'file': CSS文件的路径相对的BASE_PATH()，或流包装器URI。
 *  如："module/devel/devel.css"或"public://generated_css/stylesheet_1.css"。
 *  请注意，模块应始终保持模块名称为他们的CSS文件的名称的前缀，
 *  例如，system-menus.css而不是简单menus.css的。
 *  主题可以覆盖模块提供的CSS文件，根据它们的文件名，前缀为主题开发，
 *  有助于防止混乱的名称冲突。
 *  arial_get_css（）进行覆盖。另外，如果当前语言的方向是从右到左
 * （希伯来文，阿拉伯文等），函数也找一个RTL CSS文件附加到列表中。
 *  该文件的名称应该有一个'rtl.css'后缀。例如，一个CSS文件名
 *  为'MyModule-name.css'将有，'MyModule-name-rtl.css'文件添加到列表中，如果
 *  存在相同的目录。这个CSS文件中应包含的覆盖性能，应予以冲回或以其他方式
 *  不同，从右到左显示。
 * - 'inline': 一个字符串的CSS应该放置在给定的范围内。需要注意的是更好的做法
 *  是使用“文件”的样式表，而不是“内联”，它的CSS，然后汇总和缓存。
 * - 'external': 一个外部CSS文件，该文件不是存放在本地服务器上的绝对路径。
 *  这些文件将不会被汇总启用CSS聚集。
 * 
 * @param $options
 *  （可选）一个字符串，定义CSS的'type'中的数据参
 *   数（'file'，'inline'，或'external'），或一个数组，它可以有以下任何或
 * 所有键被添加：
 *  - 'type': 被添加的样式表的类型。可用的选项有（'file'，'inline'，或'external'）。默认为'file'。
 *  - 'basename': 强制被添加的文件基本名。模块预计将使用唯一的文件名的样式
 * 表，但整合的外部库，可以使这种不可能的。'module/node/node.css的基本名
 * 是'node.css'。如果外部库"node.js"附带"node.css"的话，将是不同的，惟一的
 * 主档名"node.js.css"。
 *  - 'group': 添加样式表组的标识号。
 *  可用的常量是：
 *  - CSS_SYSTEM：任何系统层的CSS。
 *  - CSS_DEFAULT:（默认）任何模块层的CSS。
 *  - CSS_THEME：任何主题层CSS。
 * 组号作为重量：加载一个样式表内较低的重量基的标记输出到页面加载一个样式
 * 表内的更高的权重组的标记之前，所以在较高的权重组内的CSS采取precendence
 * 在CSS内较低的重量组。
 * - 'every_page': 为了获得最佳的前端性能聚合时启用，这应该被设置为TRUE，
 * 如果样式表是在每一页的网站，为用户对他们来说，这是目前所在页.默认为false。 
 * 它是通过添加模块和主题。info文件的样式表设置为TRUE。hook_init（）的实现代  
 * 码，或者从其他的样式表，以确保所有的网页添加到模块添加样式表，也应该将此标 
 * 志设置为TRUE。所有的样式表在同一组，在“every_page”标志设置为TRUE，并没有' 
 * 预处理'集为FALSE聚集在一起，成一个单一的总文件，，总文件可以被重复使用跨用
 * 户的整个网站的访问，导致更快的页面之间的导航。然而，样式表，只需要在不经常
 * 访问的页面，可以添加代码只能运行那些特定的网页，而且代码不应该设置“every_p
 * -age”标志。这最小化了的总文件大小，用户需要下载时，首先访问的网站。
 * 没有“every_page”标志的样式表合并到一个单独的集合文件。其他聚合文件页与页
 * 之间可能会发生变化，而每一个新的聚集需要下载文件时，第一次遇到，所以应
 * 保持相对较小的保证，最常需要的样式表被添加到每一个页面。
 * - 'weight': 重量的样式表指定的顺序，会出现相对于其他样式的CSS与同组
    和“every_page'标志。样式表的确切顺序如下:
 * - 按组排序。
 * - 然后按“every_page'标志，与TRUE前FALSE。
 * - 然后按重量计。
 * - 然后通过加入的CSS中的顺序。
 * 举例来说，一切是相同的，添加的样式表通过调用arial_add_css（）发生在页面
 * 请求被添加到页面后的发生arial_add_css（）早在页面请求。
 * - 'media': 媒体类型的样式表，例如，所有print，screen。默认为'all'。
 * - 'preprocess': 如果已启用,TRUE和CSS聚合/压缩的样式将被合并和压缩.默认为true
 * - 'browsers': 一个数组，包含指定的浏览器加载CSS项目的信息。有关详细信息，
 *  请参见Arial的pre_render条件注释（）。
 *
 * @return 
 *  级联样式表排队数组。
 *
 * @see arial_get_css()
 */
function arial_add_css($data = NULL, $options = NULL) {
  $css = &arial_static(__FUNCTION__, array());

  // Construct the options, taking the defaults into consideration.
  if (isset($options)) {
    if (!is_array($options)) {
      $options = array('type' => $options);
    }
  }
  else {
    $options = array();
  }

  // 首先创建一个数组，每个媒体类型的CSS文件，因为每个服务类型需要不同的浏览器
  if (isset($data)) {
    $options += array(
      'type' => 'file',
      'group' => CSS_DEFAULT,
      'weight' => 0,
      'every_page' => FALSE,
      'media' => 'all',
      'preprocess' => TRUE,
      'data' => $data,
      'browsers' => array(),
    );
    $options['browsers'] += array(
      'IE' => TRUE,
      '!IE' => TRUE,
    );

    // 查询字符串的文件不能进行预处理。
    if ($options['type'] === 'file' && $options['preprocess'] && strpos($options['data'], '?') !== FALSE) {
      $options['preprocess'] = FALSE;
    }

    // 一定要添加一个小的重量，节省插入顺序。
    $options['weight'] += count($css) / 1000;

    // 将数据添加到CSS的类型而定的数组。
    switch ($options['type']) {
      case 'inline':
        // 对于内联样式表，我们不希望使用元数据元数据的数组的键可能是
        // 一个很长的字符串的CSS。
        $css[] = $options;
        break;
      default:
        // 本地和外部文件必须保持相同的CSS文件关联键，所以他
        // 们的名字不会被添加两次。
        $css[$data] = $options;
    }
  }

  return $css;
}

/**
 * 返回附加到该页面主题表示所有的样式。
 * 它加载CSS序列，先"module"，然后"theme"之后。
 * 这将确保正确的级联样式，主题可以很容易地通过CSS选择器样式重写模块。
 * 主题可以更换模块定义的CSS文件相同的文件名添加样式表。
 * 例如，必要的时候,themes/bartik/system-menus.css的取代module/system/system-menus.css的。
 * 这使得主题，覆盖完整的CSS文件，而不是具体的选择。
 * 如果原来的CSS文件被主题覆盖,主题是负责提供一个附带的RTL CSS文件来替换模块的。
 * @param $css
 * （可选）CSS文件的数组。如果没有设置数组，默认的样式表代替数组。
 * @param $skip_alter
 *  （可选）如果设置为TRUE时，此功能跳过arial_alter()调用$CSS，
 * 调用函数时，通过CSS数组已经改变。
 * 
 * @return
 * 一个XHTML CSS标签的字符串。
 * 
 * @see arial_add_css()
 */
function arial_get_css($css = NULL, $skip_alter = FALSE) {
  if (!isset($css)) {
    $css = arial_add_css();
  }

  // 允许模块和主题改变的CSS项目.
  if (!$skip_alter) {
    arial_alter('css', $css);
  }

  // 排序CSS项目，让他们以正确的顺序出现。
  uasort($css, 'arial_sort_css_js');

  // 提供独立使用的CSS文件，信息不可用启用CSS聚集时，信息的页面。
  // 连接后的设置，在此功能，但在这里，让CSS文件中删除以下仍被视为“拿来主义”，防止被添加在以后的AJAX请求中。
  // 跳过如果没有文件被添加到页面或jQuery.extend()将
  // 覆盖Arial.settings.ajaxPageState.css的一个空数组对象。
  if (!empty($css)) {
    // 如果不为空,甚至是在安全方面，铸造阵列的对象。
    $setting['ajaxPageState']['css'] = (object) array_fill_keys(array_keys($css), 1);
  }

  // 删除被覆盖的CSS文件。后来的CSS文件会覆盖前的。
  $previous_item = array();
  foreach ($css as $key => $item) {
    if ($item['type'] == 'file') {
      // 如果定义了此文件，强制惟一命名基本名。
      $basename = isset($item['basename']) ? $item['basename'] : arial_basename($item['data']);
      if (isset($previous_item[$basename])) {
        // 删除以前的项目，共享相同的基本名称。
        unset($css[$previous_item[$basename]]);
      }
      $previous_item[$basename] = $key;
    }
  }

  // 解析需要加载CSS的HTML页面
  $styles = array(
    '#types' => 'styles',
    '#items' => $css,
  );
  
  if (!empty($setting)) {
    $styles['#attached']['js'][] = array('type' => 'setting', 'data' => $setting);
  }

  return arial_render($styles);
}

/**
 * 排序CSS和JavaScript资源。
 * 使用以下调用uasort():
 *  - arial_get_css()
 *  - arial_get_js()
 *
 * 这种为了有助于优化前端的性能，同时提供排序CSS和JavaScript的页面上出现的必
 * 要的控制模块和主题。
 * @param $a 
 *  第一项进行比较。比较的项目应该是从arial_add_css（）或arial_add_js（）
 * 的关联数组的成员项。
 * @param $b
 *  进行比较的第二项。
 * 
 * @see arial_add_css()
 * @see arial_add_js()
 */
function arial_sort_css_js($a, $b) {
  // 第一个ORDER BY组，这样一来，例如，显示所有项目在CSS_SYSTEM组项目前在
  // 的CSS_DEFAULT组，出现之前的所有项目在CSS_THEME组。通过定义自己的常量，
  // 模块可以创建其他组。

  if ($a['group'] < $b['group']) {
    return -1;
  }
  elseif ($a['group'] > $b['group']) {
    return 1;
  }

  // 在一个组内，排序不太需要的所有常见的文件后，需要在整个网站页面的特定的文件。分离这种方式可以让所有的公用文件，可重复使用跨站点访问一个页面使用一个不太常见的文件没有被切断的总生成的文件。
  elseif ($a['every_page'] && !$b['every_page']) {
    return -1;
  }
  elseif (!$a['every_page']) && $b['every_page']) {
    return 1;
  }
  // 最后按重量排序
  elseif ($a['weight'] < $b['weight']) {
    return -1;
  }
  elseif ($a['weight'] > $b['weight']) {
    return 1;
  }
  else {
    return 0;
  }
}

/**
 * 默认回调组CSS的项目。
 * 
 * 此功能安排的CSS项目中的#item属性的样式元素成组。
 * 成组排列的CSS项目有两个目的。
 * 启用聚合时，组内的文件合并到一个文件中，显着提高页面加载性能，
 * 通过最小化网络流量开销.
 *
 * 聚合时被禁用，的分组允许多个文件被加载，从一个单一的风格标签，使网站与许多
 * 模块启用或正在使用一个复杂的主题，留在IE浏览器的31个CSS包含标签的限制：
 * http://arial.org/node/228818。
 *
 * 这个功能将在同一组中的多个项目，如果他们是相同的“媒体”和“浏览器”,
 * 如果它们是可分组。
 * 项目的'文件'类型是可分组，如果他们的'preprocess标志为TRUE时，项目的类型
 * 为'inline'总是可分组，而'external'类型的项目永远不会分组.这功能也可确保分
 * 组过程中，项目并不会改变他们的相对顺序。
 * 这一要求可能会导致在多个组中相同的类型，媒体和浏览器，如果需要的话，
 * 以适应其他项目之间。
 * 
 * @param $css
 *  CSS数组的项,如由arial_add_css()返回，但变更后进行由arial_get_css()数组。
 * @return 
 *  CSS组的数组,每个数组包含相同的键(如'media', 'data'等等),作为一个CSS项目
 *  从$ CSS参数，每个关键应用的组作为一个整体的价值。每个组还包含一个'item'键，
 * 这是$CSS，这是该组中的子集。
 * 
 * @see arial_pre_render_styles()
 * @see system_element_info()
 */
function arial_group_css($css) {
  $groups = array();
  // 如果一个组可以包含多个项目，我们跟踪的信息必须是相同的，每个项目组中的，
  // 所以，当我们遍历下一个项目，我们可以判断，如果它可以被放入当前组，或是否
  // 有新的组需要进行。
  $current_group_keys = NULL;
  // 当创建一个新组，预增$i，所以它初始化为-1，第一批将有索引为0。
  $i = -1;
  foreach ($css as $item) {
    // 浏览器的CSS项目需要加载需要一个新组时，决定的信息的一部分，但在数组中的键的顺序并不重要，如果所有的不同的是我们不希望一个新的小组。
    ksort($item['browsers']);

    // 如果该项目与其他项目进行分组，设置为group_keys到一个数组中的信息必须是
    // 相同的组中的所有项目。如果该项目不能与其他项目进行分组，设置group_keys为
    // FALSE。我们把项目为一组，可以集合在一起：他们是否会被合并到
    // _arial_css_aggregate（）函数，该函数中指定的hook_css_alter（或覆盖），
    // 但无论该功能的详细信息，一组表示可合并计算。一组可能会呈现一个单一的
    // HTML标签，该组中的所有项目必须共享相同的信息，将需要的HTML标签的一部分。
    switch ($item['type']) {
      case 'file':
        // 组文件的项目，如果他们的“预处理”标志为TRUE。帮助确保最大限度地重
        // 复使用的总文件组合在一起项目共用相同的'group'值和”every_page“标志。
        // 请参阅arial_add_css（）这一点的详细信息。
        $group_keys = $item['preprocess'] ? array($item['type'], $item['group'], $item['every_page'], $item['media'], $item['browsers']) : FALSE;
        break;
      case 'inline':
        // 始终为内联项目分组。
        $group_keys = array($item['type'], $item['media'], $item['browsers']);
        break;
      case 'external': 
        // 不要为外部项目分组
        $group_keys = FALSE;
        break;
    }
    // 如果该组密钥不匹配最近我们正工作的项目,那么创建一个新的小组是必须的。
    $if ($group_keys !== $current_group_keys) {
      $i++;
      // 初始化新的组具有相同属性的第一个项目被放入。该项目的'data'和'weight'
      // 属性是独特的项目，不应该进行的组。
      $groups[$i] = $item;
      unset($groups[$i]['data'], $groups[$i]['weight']);
      $groups[$i]['items'] = array();
      $current_group_keys = $group_keys ? $group_keys : NULL;
    }

    // 添加元素到当前的组
    $group[$i]['items'][] = $item;
  }

  return $groups;
}

/**
 * 默认回调聚合CSS文件和内嵌的内容。
 * 
 * 在浏览器中加载较少的更快的页面加载CSS文件时，它会加载很多小文件。
 * 此功能集合到一个单一的文件在同一组的文件，除非站点范围的设置，这样做
 * 是禁用（通常情况下，网站的发展过程中）
 * 为优化下载，它也压缩了​​总文件删除注释，空格，和其他不必要的内容
 * 此外，该功能聚集内嵌的内容一起，无论站点范围内的聚集设置。
 * 
 * @param $css_groups
 *  由：Arial的group_css（）返回一个数组的CSS组。
 *  此功能修改该组的数据汇总各组的属性。
 * 
 * @see arial_group_css()
 * @see arial_pre_render_styles()
 * @see system_element_info()
 */
function arial_aggregate_css(&$css_groups) {
  $preprocess_css = (variable_get('preprocess_css', FALSE) && (!defined('MAINTENANCE_MODE') || MAINTENANCE_MODE != 'update'));
  
  // 对于每个组需要聚合，聚合项目。
  foreach ($css_groups as $key => $group) {
    switch ($group['type']) {
      // 如果一个文件组可以聚合到一个单一的文件，这样做，并设置组的数据
      // 属性的集合文件的文件路径。
      case 'file':
        if ($group['preprocess'] && $preprocess_css) {
          $css_groups[$key]['data'] = arial_build_css_cache($group['items']);
        }
        break;
      case 'inline':
        $css_groups[$key]['data'] = '';
        foreach ($group['items'] as $item) {
          $css_groups[$key]['data'] .= arial_load_stylesheet_content($item['data'], $item['preprocess']);
        }
        break;
    }
  }
}

/**
 * #pre_render回调要呈现所需要的CSS标签中添加元素。
 * 
 * 对于生产网站，LINK标签最好是@import语句的风格标签，这是因为：
 * - 他们是标准的标签，用于连接到一个资源.
 * - 在Firefox 2上，也许还有其他的浏览器，CSS@import语句包含的文件不会被保存
 *   时，保存完整的网页供离线使用：http://arial.org/node/145218。
 * - 在IE中，如果只有LINK标记，而不@import语句，所有的CSS文件并行下载，从而导致
 *   更快的页面加载，但如果使用@import语句和跨多个样式的标签，所有的从一种风格
 *   下载开始前，为下一个样式标签，标签必须下载。此外，IE7不支持媒体声明
 *   的@import语句，多个样式标签时，必须使用不同的文件是不同的媒体类型.
 *   非IE浏览器下载是相同的，所以这是一个IE浏览器的具体表现
 *   怪癖：http://www.stevesouders.com/blog/2009/04/09/dont-use-import/。
 *   然而，IE的共31 CSS包含标签（http://arial.org/node/228818）和LINK标记被限制
 *   在一个文件中，每个标签有一个恼人的限制，而样式标签可以包含多个@import语句
 *   允许多个文件每个标签被载入。当禁用CSS聚集，Drupal站点可以轻松拥有超过31个
 *   CSS文件，需要加载，所以使用专用的LINK标签会导致一个网站，将正确显示在IE.
 *   根据不同的需求，不同的策略可以用来决定何时使用LINK标签和使用样式标签。
 *   此功能采用的战略是，以使用LINK标签为所有聚合文件和所有文件，可以不进行汇
 *   总（例如，如果'预处理'被设定到FALSE或“外部”的类型）的，并以使用样式标签
 *   的群体文件可以合并在一起，但都没有（例如，如果站点范围内的聚合设置被禁用）。
 *   这样的结果在所有的LINK标签聚合时启用，保证尽可能多的或仅略多一点，标签是用
 *   来比启用已禁用的聚集（的限制，如果要跨越和聚集功能的网站开发人员也注意到这
 *   个问题而聚集禁用），和一个简单的方法，为开发人员查看HTML源，同时聚合被禁用
 *   ，并且知道哪些文件会被聚合在一起，聚合时将变为启用。
 * 
 * @param $element
 *  渲染数组包含:
 * - '#items': CSS项目返回由arial_add_css（），并改变由arial_get_css（）。
 * - '#group_callback': 要调用的函数组#items通过整合文件和/或使用多个@import
 *    语句在一个单一的标签，以便能够使用较少的标签。
 * - '#aggregate_callback': 要调用的函数内的个组安排#group_callback功能的
 *    汇总项目。
 * @return 
 *  一个Render的数组将呈现为一个字符串的XHTML CSS标签。
 *
 * @see arial_get_css()
 */
function arial_pre_render_styles($elements) {
  // 分组或聚合项目
  if (isset($elements['#group_callback'])) {
    $elements['#groups'] = $elements['#group_callback']($elements['#items']);
  }
  if (isset($elements['#group_callback'])) {
    $elements['#aggregate_callback']($elements['#groups']);
  }

  // 一个虚拟的查询字符串添加到文件名，从而获得控制浏览器的缓存。字符串在每
  // 次更新或完整的高速缓存刷新的​​变化，迫使浏览器加载一个新的文
  // 件副本，作为URL改变。
  $query_string = variable_get('css_js_query_string', '0');

  // 内联CSS验证XHTML，所有含XHTML的CSS需要被包裹在CDATA。为了向后兼
  // 容HTML 4，我们需要注释掉CDATA标签。
  $embed_prefix = "\n<!--/*--><![CDATA[/*><!--*/\n";
  $embed_suffix = "\n/*]]*/-->\n";

  // LINK和STYLE元素的默认值。
  $link_element_defaults = array(
    '#type' => 'html_tag',
    '#tag'  => 'link',
    '#attributes' => array(
      'type' => 'text/css',
      'rel'  => 'stylesheet',
    ),
  );
  $style_element_defaults = array(
    '#type' => 'html_tag',
    '#tag'  => 'style',
    '#attributes' => array(
      'type' => 'text/css',
    ),
  );

  // 通过各组的循环。
  foreach ($elements['#groups'] as $group) {
    switch ($group['type']) {
      // 对于文件的项目中，有三种可能性。
      // - 本分组已汇总：在这种情况下，输出的总文件的LINK标记。 
      // - 组可以被合并，但一直没有（很可能是因为网站管理员禁用了站点范围的设
      //  置）：在这种情况下，尽可能少的风格标签组可能的话，使用@import语句为
      //  每个文件组中的输出。这使我们能够留在IE浏览器的限制，共31件的的CSS包
      //  含的标签。 
      case 'file':
        // 本分组已合并成一个文件输出的总文件的LINK标记。
        if (isset($group['data'])) {
          $element = $link_element_defaults;
          $element['#attributes']['href'] = file_create_url($group['data']);
          $element['#attributes']['media'] = $group['media'];
          $element['#browsers'] = $group['browsers'];
          $element[] = $element;
        }
        elseif ($group['preprocess']) {
          $import = array();
          foreach ($group['items'] as $item) {
            // 一个theme.info文件可能有一个条目作为一种压倒一切的一个模块或基本
            //主题CSS文件被添加到页面的文件不存在.通常情况下，file_exists()调用
            //需要运行的每一个页面请求应最小化，但是这是正常的，因为它只能运行/
            //禁用CSS聚集时。足够的负荷沉重的file_exists（）调用都需要被最小化
            //，CSS聚集在一个服务器上启用，在这种情况下，这段代码无法运行。聚合
            //时启用中，arial_load_stylesheet（）检查file_exists（），但只有当
            //建设的总的文件，然后将其重复使用许多页面请求。
            if (file_exists($item['data'])) {
              // 虚假的查询字符串添加到URL来控制浏览器的缓存。IE7不支持的媒体类
              // 型的@ import语句，所以我们改为指定的媒体组的风格标签。
              $import[] = '@import url("' . checkplain(file_create_url($item['data']) . '?' . $query_string) . '");';
            }
          }

          // 除了IE浏览器的限制，共31 CSS包含标签，它也是有限制的31@ import语句
          // ，每款标签。
          while (!empty($import)) {
            $import_batch = array_slice($import, 0, 31);
            $import = array_slice($import, 31);
            $element = $style_element_defaults;
            $element['#value'] = implode("\n", $import_batch);
            $element['#attributes']['media'] = $group['media'];
            $element['#browsers'] = $group['browsers'];
            $element[] = $element;
          }
        }

        // 该组包含的项目不符合资格聚集：一个的LINK标记为每个文件输出。
        else {
          foreach ($group['items'] as $item) {
            // 我们不检查file_exists（），因为这段代码运行文件的“预处理”设置
            // 为FALSE，并因此，即使启用聚合时，我们要避免不必要的征税可能是在
            // 重负载下的服务器。 file_exists（）执行上述文件的'预处理'TRUE为主            // 题的利益。info文件，但代码的预处理'是假的，是负责确保该文件存在
            // 的文件。假的查询字符串添加到URL来控制浏览器的缓存。
            $query_string_separator = (strpos($item['data'], '?') !== FALSE) ? '&' : '?';
            $element['#attributes']['href'] = file_create_url($item['data']) . $query_string_separator . $query_string;
            $element['#attributes']['media'] = $item['media'];
            $element['#browsers'] = $group['browsers'];
            $elements[] = $element;
          }
        }
        break;

        // 内嵌的内容，在“数据”属性包含CSS内容。如果本集团的“数据”属性设置，然
        // 后将其输出在一个单一的风格标签。否则，输出一个单独的样式标签的每个项
        // 目。
        case 'inline':
          if (isset($group['data'])) {
            $element = $style_element_defaults;
            $element['#value'] = $group['data'];
            $element['#value_prefix'] = $embed_prefix;
            $element['#value_suffix'] = $embed_suffix;
            $element['#attribute']['media'] = $group['media'];
            $element['#browsers'] = $group['browsers'];
            $elements[] = $element;
          }
          else {
            foreach ($group['items'] as $item) {
              $element = $style_element_defaults;
              $element['#value'] = $item['data'];
              $element['#value_prefix'] = $embed_prefix;
              $element['#value_suffix'] = $embed_suffix;
              $element['#attributes']['media'] = $item['media'];
              $element['#browsers'] = $group['browsers'];
              $elements[] = $element;
            }
          }
          break;
         case 'external':
          foreach ($group['items'] as $item) {
            $element = $link_element_defaults;
            $element['#attributes']['href'] = $item['data'];
            $element['#attributes']['media'] = $item['media'];
            $element['#browsers'] = $group['browsers'];
            $elements[] = $element;
          }
          break;
    }
  }

  return $elements;
}


/**
 * 汇总和优化CSS文件到缓存中的文件目录中的文件。
 * 
 * CSS缓存文件的文件名所产生的哈希值的聚合$ CSS文件中的内容。这将强制代理和浏
 * 览器下载新的CSS时，CSS的变化。
 * 通过查找变量，它包含一个关联数组，一个页面加载的缓存文件名进行检索。数组的
 * 键是$ CSS中的文件名的哈希值，该值是缓存文件名称。
 * 在两种情况下产生的缓存文件。首先，如果没有文件名的键值，将发生什么，如果一 * 个新的文件名已经被添加到CSS或查找变量被清空缓存的强制重建后。
 * 二，如果缺少磁盘上的缓存文件。旧的缓存文件将不会被删除时，立即查找变量是空 * 的，但经过一段由arial_delete_file_if_stale（）都将被删除。这将确保缓存的  * 页面中引用的文件仍然可以使用。
 * 
 * @param $css
 *  CSS文件数组汇总并压缩成一个文件。
 * @return 
 *  URI的的CSS缓存文件，或者FALSE，则该文件无法保存。
 */
function arial_build_css_cache($css) {
  $data = '';
  $uri  = '';
  $map  = variable_get('arial_css_cache_files', array());
  // 因此，只有文件名用于创建哈希表，创建一个新的数组。这样可以防止新的聚合体
  // 正在创建不必要的。
  $css_data = array();
  foreach ($css as $css_file) {
    $css_data[] = $css_file['data'];
  }
  $key = hash('sha256', serialize($css_data));
  if (isset($map[$key])) {
    $uri = $map[$key];
  }

  if (empty($uri) || !file_exists($uri)) {
    // 构建聚合CSS文件.
    foreach ($css as $stylesheet) {
      // 只有“文件”样式表可以合并计算。
      if ($stylesheet['type'] == 'file') {
        $contents = arial_load_stylesheet($stylesheet['data'], TRUE);

        // 建立这个CSS文件的基础URL：完整的URL。
        $css_base_url = file_create_url($stylesheet['data']);
        // 移动到父级
        $css_base_url = substr($css_base_url, 0, strrpos($css_base_url, '/'));
        // 如果样式表的URL开始，基地网站的网址，简化的相对URL。
        if (substr($css_base_url, 0, strlen($GLOBALS['base_root'])) == $GLOBALS['base_root']) {
          $css_base_url = substr($css_base_url, strlen($GLOBALS['base_root']));
        }

        _arial_build_css_path(NULL, $css_base_url . '/');

        // 锚定在CSS中的所有路径的基础URL，忽略外部路径和绝对路径。
        $data .= preg_replace_callback('/url\(\s*[\'"]?(?![a-z]+:|\/+)([^\'")]+)[\'"]?\s*\)/i', '_arial_build_css_path', $contents);
      }
    }

    // 在每的W3C规范在http://www.w3.org/TR/REC-CSS2/cascade.html#at-import，@ import规则必须进行的其他任何样式，所以我们将这些顶端。
    $regexp = '/@import[^;]+;/i';
    preg_match_all($regexp, $data, $matches);
    $data = preg_replace($regexp, '', $data);
    $data = implode('', $matches[0]) . $data;

    // 前缀的文件名拒绝“的广告”开头的文件通过防火墙，以防止阻塞。
    $filename = 'css_' . arial_hash_base64($data) . '.css';
    // 创建的CSS/的文件夹。
    $csspath = 'public://css';
    $uri = $csspath . '/' . $filename;
    // 创建css文件
    file_prepare_directory($csspath, FILE_CREATE_DIRECTORY);
    if (!file_exists($uri) && !file_unmanaged_save_data($data, $uri, FILE_EXISTS_REPLACE)) {
      return FALSE;
    }

    // 如果启用gzip压缩CSS，整洁的网址启用（这意味着重写规则），并在zlib扩展
    //可用，则该文件创建一个gzip压缩过的版本。提供该文件是有条件地接受gzip的
    // 浏览器。htaccess规则。
    if (variable_get('css_gzip_compression', TRUE) && variable_get('clean_url', 0) && extension_loaded('zlib')) {
      if (!file_exists($uri . '.gz') && !file_unmanaged_save_data(gzencode($data, 9, FORCE_GZIP), $uri . '.gz', FILE_EXISTS_REPLACE)) {
        return FALSE;
      }
    }
    // 保存上传地址
    $map[$key] = $uri;
    variable_set('arial_css_cache_files', $map);
  }
}

/**
 * 为每个css文件添加前缀arial_build_css_cache().
 */
function _arial_build_css_path($matches, $base = NULL) {
  $_base = &arial_static(__FUNCTION__);
  // 使用preg_replace_callback替换存储地址
  if (isset($base)) {
    $_base = $base;
  }

  // 移除'../'和在合适的地方添加前缀
  $path = $_base . $matches[1];
  $last = '';
  while ($path != $last) {
    $last = $path;
    $path = preg_replace('`(^|/)(?!\.\./)([^/]+)/\.\./`', '$1', $path);
  }
  return 'url(' . $path . ')';
}

/**
 * 全部使用@import命令处理加载样式表
 * 
 * 加载样式表,并替换@import命令导入的文件的内容。处理样式表时使用@import，
 * 而不是file_get_contents。
 * 只有在启用CSS聚集时,返回被压缩的内容，去除空白和注释。这种优化将不适用启
 * 用为color.module的主题的CSS聚集关闭的。
 * 
 * @param $file
 *  被处理的样式表名称
 * @param $optimize
 *  被处理的样式表是否可以被压缩
 * @param $reset_basepath
 *  在内部使用，以方便@ import命令递归解析。
 * 
 * @return 
 *  在样式表中的内容，包括任何处理的@ import命令。
 */
function arial_load_stylesheet($file, $optimize = NULL, $reset_basepath = TRUE) {
  // 这些静态变量是不缓存变量，所以我们不使用arial_static的()。
  static $_optimize, $basepath;
  if ($reset_basepath) {
    $basepath = '';
  }
  // 嵌套的@import循环进行优化，preg_replace_callback存储的值。
  if (isset($optimize)) {
    $_optimize = $optimize;
  }

  // 样式表是彼此相对的。首先，添加一个基本路径前缀提供的的父样式表
  //（如果需要的话）。
  if ($basepath && !file_uri_scheme($file)){
    $file = $basepath . '/' . $file;
  }
  $basepath = dirname($file);

  // 加载CSS样式表。抑制错误，因为主题可以在.info文件中指定样式表的路径中是否
  // 不存在的，但仅仅是禁用某些模块的CSS文件。

  if ($contents = @file_get_content($file)) {
    // 返回被处理的样式表。 
    return arial_load_stylesheet_content($contents, $_optimize);
  }

  return '';
}

/**
 * 处理聚集的样式表的内容。
 * @param $contents
 *  样式表的内容
 * @param $optimize
 *  (可选) 布尔CSS内容是否应压缩。默认为false。
 * 
 * @return 
 *  包括被导入的样式表，样式表的内容。
 */
function arial_load_stylesheet_content($contents, $optimize = FALSE) {
  // 删除多个字符集标准的符合性声明（固定Safari浏览器问题）。
  $contents = preg_replace('/^charset\s+[\'"](\S*)\b[\'"];/i', '', $contents);
  if ($optimize) {
    // 执行一些安全CSS优化。
    // 正则表达式匹配的注释块。
    $comment = '/\*[^*]*\*+(?:[^/*][^*]*\*+)*/';
    // 正则表达式匹配双引号字符串。 
    $double_quot = '"[^"\\\\]*(?:\\\\.[^"\\\\]*)*"';
    // 正则表达式匹配单引号字符串.
    $single_quot = "'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'";
    // 剥除所有注释块，但保持双/单引号的字符串。
    $contents = preg_replace(
      "<($double_quot|$single_quot)|$comment>Ss)",
      "$1",
      $contents
    );

    // 卸下一定的空白。根据不同的条件删除开头和结尾的空格。
    // @see http://php.net/manual/en/regexp.reference.subpatterns.php
    $contents = preg_replace('<
      # 剥除开头和结尾的空白。
        \s*([@{};,])\s*
      # 剥除前导空格：右括号：保留“@media (bar) 和foo”。
      | \s+([\)])
      # 仅剥尾部的空白：
      # - 左括号：保留“@media (bar) 和foo”。
      # - 冒号:  保留：伪选择器。
      | ([\(:])\s+
      >xS',
      // 3个捕获组中只有一个匹配，所以它的引用将包含所需要的值将被替换
      // 为空字符串和引用两个不匹配的组。
      '$1$2$3',
      $contents
      );    
    // 新行结尾
    $contents = trim($contents);
    $contents .= "\n";
  }

  // 替换@ import命令与实际的样式表的内容.发生这种情况递归,但忽略了外部文件。
  $contents = preg_replace_callback('/@import\s*(?:url(\(\s*)?[\'"]?(?![a-z]+:)([^\'"\()]+)[\'"]?\s*\)?\s*;/', '_arial_load_stylesheet', $contents);

  return $contents;
}

/**
 * 加载样式表的递归并返回正确路径的内容。
 * 
 * 此功能用于递归加载样式表,并返回所有正确url()路径的样式表的内容。
 */ 
function _arial_load_stylesheet($matches) {
  $filename = $matches[1];
  // 用@import命令替换加载导入的样式表。
  $file = arial_load_stylesheet($filename, NULL, FALSE);

  // 确定文件目录
  $directory = dirname($filename);

  // 如果该文件是在当前目录中,确保'.'目录不会出现在url()路径中
  $directory = $directory == '.' ? '' : $directory . '/';

  // 改变所有的内部URL（）路径。单独保留外部路径。我们并不需要，因为
  // 这将在以后进行规范化的绝对路径（即删除文件夹/段）。
  return preg_replace('/url\(\s*([\'"]?)(?![a-z]+:|\/+)/i', 'url(\1'. $directory, $file);
}

/**
 * 删除旧的缓存样式文件
 */
function arial_clear_css_cache() {
  variable_del('arial_css_cache_file');
  file_scan_directory('public://css', '/.*/', array('callback' => 'arial_delete_file_if_stale'));
}

/**
 * 回调删除修改过的文件超过设定的时间前。
 */
function arial_delete_file_if_stale($uri) {
  // 默认过期阈值是30天
  if (REQUEST_TIME - filemtime($uri) > variable_get('arial_stale_file_threshold', 2592000)) {
    file_unmanaged_delete($uri);
  }
}

/**
 * 准备一个字符串作为一个的CSS识别码（element, class, 或 name）。
 *
 * http://www.w3.org/TR/CSS21/syndata.html#characters 
 * 显示了有效的CSS标识符（包括元素名，类和ID选择器的语法）。
 * 
 * @param $identifier
 *  标识符
 * @param $filter
 *  使用字符串替换的标识符数组。
 *
 * @return 
 *  返回整洁的标识符
 */
function arial_clean_css_identifier($identifier, $filter = array(' ' => '-', '_' => '-', '/' => '-', '[' => '-', ']' => '')) {
  // 默认情况下，过滤器使用Drupal的编码标准。
  $identifier = strtr($identifier, $filter);

  // CSS标识的有效字符是：
  // - 连字符 (U+002D)
  // - a-z (U+0030 - U+0039)
  // - A-Z (U+0041 - U+005A)
  // - 下划线 (U+005F)
  // - 0-9 (U+0061 - U+007A)
  // - ISO 10646国际编码字符U+00A1或更高
  // 我们没有在上面的列表中剥离出的任何字符。
  $identifier = preg_replace('/[^\x{002D}\x{0030}-\x{0039}\x{0041}-\x{005A}\x{005F}\x{0061}-\x{007A}\x{00A1}-\x{FFFF}]/u', '', $identifier);

  return $identifier;
}

/**
 * 准备一个字符串作为有效的类名。
 * 
 * 不要传递一个字符串，其中包含多个类，因为它们会被错误地用破折号连接起来，
 * “one two”将成为“one-two”。
 *
 * @param $class 
 *  类名
 * @return 
 *  返回的类名
 */
function arial_html_class($class) {
  arial_clean_css_identifier(arial_strtolower($class)); 
}

/**
 * 准备一个字符串作为一个有效的HTML ID，并保证唯一性。
 * 此功能可确保每个通过HTML ID值在页面上只存在一次。
 * 通过跟踪已经返回IDS的，该功能可在同一页上多次输出的形式，块，和其他内容，
 * 而不会破坏(x)HTML验证。
 * 对于已经存在的ID，一个计数器被所附的ID字符串。因此，JavaScript和CSS代码不
 * 应依靠此功能所产生的任何值，而应依靠手动添加CSS类或类似的可靠结构。
 * 两个连续的连字符分开计数器从原始ID。
 * 要管理多个Ajax请求在同一页上的唯一性，Ajax请求后，这是灌注在第一次调用此
 * 函数的缓存的页面上当前存在的所有ID的数组。
 * 要允许反向解析，通过Ajax，多个连续的连字符在最初通过ID提交的ID被替换为
 * 一个连字符。
 *
 * @param $id
 * 
 * @return 
 */ 
function arial_html_id($id) {
  // 如果这是一个Ajax请求，然后返回本页面请求的内容将被合并的内容的基础上。
  // 因此，初始化$seen_ids考虑到帐户ID已经在使用的基础上。
  $seen_ids_init = &arial_static(__FUNCTION__ . ':init');
  if (!isset($seen_ids_init)) {
    // 理想的情况是，Arial将提供一个API来保持之前的页面请求在数据库中的状态信
    // 息，我们就能够添加此功能的$ seen_ids静态变量，状态信息，才能有正确初始
    // 化此页面请求。然而，没有这样的页面状态的API存在，而不是ajax.js将所有使
    // 用中的HTML标识的Ajax提交的POST数据。通常不建议直接使用$ _POST，因为它
    // 可以打开的安全隐患，但因为POST的原始数据转换为一个数字之前，这个函数返
    // 回的，这种用法是安全的。
    if (empty($_POST['ajax_html_ids'])) {
      $seen_ids_init = array();
    }
    else {
      // 此功能可以确保唯一性，通过附加一个计数器，通过调用函数后第一次出现
      // 的该请求的ID编号要求的基础。 
      foreach ($_POST['ajax_html_ids'] as $seen_id) {
        // 我们依靠'--'完全用于分离基地的id的计数器，它返回一个ID时，此功能可
        // 确保。
        $parts = explode('--', $seen_id, 2);
        if (!empty($parts[1]) && is_numeric($parts[1])) {
          list($seen_id, $i) = $parts;
        }
        else {
          $i = 1;
        }
        if (!isset($seen_ids_init[$seen_id]) || ($i > $seen_ids_init[$seen_id])) {
          $seen_ids_init[$seen_id] = $i;
        }
      }
    }
  }
  $seen_ids = &arial_static(__FUNCTION__, $seen_ids_init);

  $id = strtr(arial_strtolower($id), array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));

  // 在http://www.w3.org/TR/html4/types.html#type-name的定义，HTML的ID只能包
  // 含字母，数字（[0-9]），连字符（'-'），下划线（'_'），冒号（':'）和
  // 句号（'.'）。
  // 我们去掉不在该列表中的任何字符。需要注意的是CSS规范不允许冒号或句点的标
  // 识（http://www.w3.org/TR/CSS21/syndata.html#characters），所以我们去掉这
  // 两个字符以及。
  $id = preg_replace('/[^A-Za-z0-9\-_]/', '', $id);

  // 删除多个连续的连字符。
  $id = preg_replace('/\-+/', '-', $id);
  // 确保ID是唯一的由后追加一个计数器的第一次出现。该计数器需要追加与不存在的
  // 固定标识（base ID）中的分隔符。 
  // 需要一个独特的分隔符可以确保我们真的返回唯一的ID，也有助于我们重新建立在
  // Ajax请求$ seen_ids数组。
  if (isset($seen_ids[$id])) {
    $id = $id . '--' . ++$seen_ids[$id];
  }
  else {
    $seen_ids[$id] = 1;
  }

  return $id;
}

/**
 * 提供标准的HTML页面区域的类的名称标识。
 *
 * 建议该模板的预处理功能适用于这个类的任何页面区域输出的主题（Arial核心已经
 * 处理这个问题的标准模板，预处理实现）。
 * 
 * 在这样的类名规范允许模块来实现某些功能，如拖放和拖放或动态的Ajax加载，在主
 * 题无关的方式。
 *
 * @param $region
 *  页面区域（例如, 'page_top' 或 'content'）的名称。
 * @return 
 *  一个HTML标识的区域（例如，'region-page-top'或'region-content'）的类。
 *
 * @see template_preprocess_region()
 */
function arial_region_class($region) {
  return arial_html_class("region-$region");
}

/**
 * 添加一个JavaScript文件，设置，或内联代码的页面。
 * 
 * 此函数的行为依赖于它被称为参数。
 * 一般情况下，它可以处理增加的JavaScript的网页，无论是作为参考现有的文件或内
 * 联代码。
 * 使用此功能，可以进行以下操作：
 * - 添加一个文件（'file'）：添加一个JavaScript文件的页面。
 * - 添加内联的JavaScript代码('inline')：在当前页面上执行一段JavaScript代码，
 *  将代码直接在页面(例如，通过打开一个弹出警告框，告诉用户一个新的消息到达等
 *  这应该只用于为JavaScript,不能执行从一个文件。
 *  当添加内联代码，确保你不是依赖于$()jQuery的函数。
 *  将代码包裹在:
 * @code
 *  (function($) {...})(jQuery);
 * @endcode
 * 或者使用jQuery()代替$()。
 * - 添加外部JavaScript('external'): 允许包含没有在本地服务器上托管的外
 *   部JavaScript文件。请注意，这些外部JavaScript引用时，没有得到汇总预处理。
 * - 添加设置('setting'): 将设置添加到Arial的全局存储的JavaScript设置中。 
 *   每个页面的设置是必需的一些模块才能正常工作。
 *   Drupal.settings所有设置将被允许访问。
 * 示例代码:
 * @code 
 *  arial_add_js('misc/collapse.js');
 *  arial_add_js('misc/collapse.js', 'file');
 *  arial_add_js('jQuery(document).ready(function() { alert("Hello!");});', '
 *          inline');
 *  arial_add_js('jQuery(document).ready(function() { alert("Hello!");});', 
 *          array('type' => 'inline', 'scope' => 'footer', 'weight' => 5)
 *  );
 *  arial_add_js('http://example.com/example.js', 'external');
 *  arial_add_js(array('myModule' => array('key' => 'value')), 'setting');
 * @endcode
 * 
 * 调用arial_static_reset('arial_add_js')将会清除Javascript设置.
 *
 * 如果JavaScript聚集启用时，所有的JavaScript文件中添加$options['preprocess']
 * 设置为TRUE将被合并成一个总的文件。
 * 预处理内嵌JavaScript将无法被聚合到这个单一的文件。
 * 外部托管的JavaScript代码永远不会合并计算。
 * 究其原因，聚集的文件在这里非常全面的概述：
 * http://www.die.net/musings/page_load_time/“载入较少的外部对象。
 * 由于请求的开销，一个更大的文件加载速度相当于两个较小的文件加载速度的一半
 * 大小。$options['preprocess']应该只有一个文件时所需的所有典型的游客和大多数
 * 的网站页面设置为TRUE。
 * 至关重要的是，所有无条件预处理的文件被添加在每一页上，即使这些文件并不需
 * 要在页面上。这通常是通过调用arial_add_js()在hook_init()实现。
 * 
 * 当它们需要时,非预处理的文件被添加到页面时。
 * 
 * @param $data
 *  (可选) 如果$options作为一个关联数组传入,其值依赖于$options参数
 *         或$option['type'].
 * - 'file': 相对于base_path()的文件路径
 * - 'inline': JavaScript代码应放置在给定的范围内。
 * - 'external': 启用如果JavaScript聚集,这些不是存放在本地服务器上的一个外
 *         部JavaScript文件的绝对路径的文件将不会被合并。
 * - 'setting': 一个配置选项关联数组。该数组合并直接到Arial.settings。
 *         在Arial.settings命名空间所有模块都应该包括里实际配置设置在另一个变
 *         量的防止冲突。项目添加一个字符串键，将取代该键现有的设置与数字数组
 *         的键将被添加到现有的设置数组。
 * @param $options
 *  (可选) 一个字符串，定义中添加的数据参数类型（'file'/'setting'/'inline'
 *   /'external'）,或一个关联数组JavaScript。JavaScript设置应始终传递字符
 *  串“设置”。其他类型数组中的元素可以有以下几种：
 * - type: JavaScript的类型，即是要添加到页面。允许的值是'file', 'inline',
 *   'external' or 'setting'.默认为'file'。
 * - scope: 在哪个位置要放置的脚本。可能的值是'header'或'footer'.如果你的主
 *   题实现了不同地区，您也可以使用这些。默认为'header'。
 * - group: 一个标识号的组中添加JavaScript。可用的常量是：
 *     - JS_LIBRARY: 任何库，设置或jQuery插件。
 *     - JS_DEFAULT: 任何模块层的JavaScript。
 *     - JS_THEME:  任何主题层的JavaScript。
 * 在一个较低的重量组的组数作为权重：JavaScript的页面之前在一个较高的权重。
 * - every_page: 启用聚合时的最佳前端性能，这应设置为TRUE，JavaScript是存在
 * 于每一个页面的网站对用户，对他们来说，这是目前在所有。默认为false。
 * 它被设置为TRUE，JavaScript文件，通过添加模块和主题.info文件。
 * 模块内添加JavaScript hook_init（）的实现，或者从其他的JavaScript添加到
 * 所有的网页的代码，以确保还应将此标志设置为TRUE。
 * 
 * 所有的Javascript文件在同一组和，在“every_page”标志设置为TRUE，并没有'预处
 * 理'集为FALSE都汇集在一起成一个单一的总文件，和，总文件可以被重复使用跨用户
 * 的整个网站的访问，从而导致更快的页面之间的导航。
 * 然而，JavaScript，只需要对不经常访问的页面，可以添加代码，只对那些特定的
 * 页面上运行，而且代码不应该设置“every_page”标志。
 * 这最小化了的总文件大小，用户需要下载时，首先访问的网站。
 * 没有“every_page”标志的JavaScript合并到一个单独的集合文件。其他聚合文件页
 * 与页之间可能会发生变化，而每一个新的聚集需要下载文件时，首先遇到的，所以它
 * 应该保持相对较小确保最常需要的JavaScript添加到每一个页面。
 * ...
 *   JavaScript是确切的顺序如下：
 *   - 首先的范围,'header','footer'最后,和任何其他范围之间,确定的主题自定义主题
 *   - 然后组。
 *   - 然后，按重量计。
 *   - 然后按顺序的JavaScript。例如，所有其他条件相同的，JavaScript的调用
 *   arial_add_js（）发生后来被添加到页面后，在页面请求的发生arial_add_js()
 *   早在页面请求。
 * - defer:  如果设置为TRUE，defer属性设置<script>标签。默认为false。
 * - cache:  如果设置为FALSE，重新加载JavaScript文件每一页上调用，换句话说，它
 *   是不会被缓存。只有当“类型”引用一个JavaScript文件。默认为true。
 * - preprocess: 如果是TRUE和JavaScript聚集启用，该脚本文件将一并计算。默认为true。
 * @return 
 *  当前的数组中的JavaScript文件，设置和行代码，包括Drupal的默认值，以前添加的
 * 任何内容与的通话arial_add_js()，这个函数调用的增加。
 */
function arial_add_js($data = NULL, $options = NULL) {
  $javascript = &arial_static(__FUNCTION__, array());

  // 构建选项，把默认考虑进去.
  if (isset($options)) {
    if (!is_array($options)) {
      $options = array('type' => $options);
    }
  }
  else {
    $options = array();
  }
  $options += arial_js_defaults($data);

  // 如果启用了高速缓存，只能设置预处理.
  $options['preprocess'] = $options['cache'] ? $options['preprocess'] : FALSE;

  // 调整的权重相同的权重，使文件的调用的顺序包含在arial_add_js().
  $options['weight'] += count($javascript) / 1000;

  if (isset($data)) {
    // 添加的jquery.js和arial.js的,以及基本路径设置,
    // 第一次一个JavaScript文件中添加.
    if (empty($javascript)) {
      //url()生成的前缀,使用hook_url_outbound_alter().而不是在这里再次运行
      // hook_url_outbound_alter(),提取前缀url()。 
      url('', array('prefix' => &$prefix));
      $javascript = array(
        'settings' => array(
          'data' => array(
            array('basePath' => base_path()),
            array('pathPrefix' => empty($prefix) ? '' : $prefix),
          ),
          'type' => 'setting',
          'scope' => 'header',
          'group' => JS_LIBRARY,
          'every_page' => TRUE,
          'weight' => 0,
        ),
        'misc/arial.js' => array(
          'data' => 'misc/arial.js',
          'type' => 'file',
          'scope' => 'header',
          'group' => JS_LIBRARY,
          'every_page' => TRUE,
          'weight' => -1,
          'preprocess' => TRUE,
          'cache' => TRUE,
          'defer' => FALSE,
        ),
      );
      //注册所需的所有库。 
      arial_add_library('system', 'jquery', TRUE);
      arial_add_library('system', 'jquery.once', TRUE);
    }

    switch ($options['type']) {
      case 'setting':
        //页面的头被放置在所有的JavaScript设置与库的重量，以使内嵌脚本之后出现
        $javascript['settings']['data'][] = $data;
        break;

      case 'inline':
        $javascript[] = $options;
        break;

      default: // 'file' and 'external'
        // 本地和外部的文件必须保持他们的名字关联的关键，所以同一
        // 个JavaScript文件不会被添加两次.
        $javascript[$options['data']] = $options;
    }
  }
  return $javascript;
}

/**
 *构造一个数组的默认值所使用的JavaScript项目.
 *
 * @param $data
 *  （可选）默认的数据参数的JavaScript项数组. 
 *
 * @see arial_get_js()
 * @see arial_add_js()
 */
function arial_js_defaults($data = NULL) {
  return array(
    'type' => 'file',
    'group' => JS_DEFAULT,
    'every_page' => FALSE,
    'weight' => 0,
    'scope' => 'header',
    'cache' => TRUE,
    'defer' => FALSE,
    'preprocess' => TRUE,
    'version' => NULL,
    'data' => $data,
  );
}

/**
 * 返回主题演示当前页面的所有JavaScript代码.
 *
 * JavaScript文件被放置在一个特定的顺序: 首先，所有的'core'文件，然后所有
 * 的'module'，最后所有的'theme'文件, JavaScript文件被添加到页面中。 然后，所有
 * 的设置都通过内嵌的JavaScript代码输出。 如果运行update.php，所有的预处理被
 * 禁用。
 * 需要注意的是hook_js_alter(JavaScript)的过程中调用此函数调用允许修改在演示
 * 中的JavaScript。 调用从hook_js_alter()到arial_add_js()不会被添加的输出
 * 演示。添加JavaScript，在hook_js_alter()是正确的方法添加另一个元素的
 * JavaScript数组，来自arial_js_defaults(). 请参阅locale_js_alter（）这样的一
 * 个例子。
 * @param $scope
 *   (optional) 该范围应返回的JavaScript规则。默认为'header'.
 * @param $javascript
 *   (optional) 一个数组的所有JavaScript代码。默认为JavaScript数组给定的范围内。
 * @param $skip_alter
 *   (optional) 如果设置为TRUE，这个功能会跳过调用arial_alter()$JavaScript的，
 *  当调用函数传递一个已经改变$JavaScript数组是有用的.
 *
 * @return
 *  所有的JavaScript代码段，其中包括HTML标签的范围.
 *
 * @see arial_add_js()
 * @see locale_js_alter()
 * @see arial_js_defaults()
 */
function arial_get_js($scope = 'header', $javascript = NULL, $skip_alter = FALSE) {
  if (!isset($javascript)) {
    $javascript = arial_add_js();
  }
  if (empty($javascript)) {
    return '';
  }

  //允许模块更改JavaScript.
  if (!$skip_alter) {
    arial_alter('js', $javascript);
  }

  // 筛选出给定范围内的元素.
  $items = array();
  foreach ($javascript as $key => $item) {
    if ($item['scope'] == $scope) {
      $items[$key] = $item;
    }
  }

  $output = '';
  // 索引计数器是用来保持聚集和非聚集的文件，以重量排序.
  $index = 1;
  $processed = array();
  $files = array();
  $preprocess_js = (variable_get('preprocess_js', FALSE) && (!defined('MAINTENANCE_MODE') || MAINTENANCE_MODE != 'update'));

  // 一个虚拟的查询字符串添加到文件名，从而获得控制浏览器的缓存。字符串在每次更新或完整的高速缓存刷新的变化，迫使浏览器加载一个新的文件副本，作为URL改变。得到REQUEST_TIME，而不是作为查询字符串，执行每一个页面请求重装，不应该被缓存的文件(见arial_add_js()).
  $default_query_string = variable_get('css_js_query_string', '0');

  // 对于内联的JavaScript验证XHTML，所有的JavaScript需要被包裹在CDATA包含XHTML.
  // 为了向后兼容HTML 4，我们需要注释掉CDATA标签.
  $embed_prefix = "\n<!--//--><![CDATA[//><!--\n";
  $embed_suffix = "\n//--><!]]>\n";

  // 由于JavaScript可能在寻找参数中的URL和对他们采取行动，一些第三方的代码可能
  // 需要使用不同的查询字符串.
  $js_version_string = variable_get('arial_js_version_query_string', 'v=');

  // 所以，它出现在正确的顺序，排序的JavaScript.
  uasort($items, 'arial_sort_css_js');

  // 提供个人使用的JavaScript文件的信息，信息不启用聚合时的页面.
  $setting['ajaxPageState']['js'] = array_fill_keys(array_keys($items), 1);
  unset($setting['ajaxPageState']['js']['settings']);
  arial_add_js($setting, 'setting');

  // 如果我们输出的头范围，那么这可能是最后一次，arial_get_js()，所以输出以及
  // 的arial_add_js()缓存的设置。如果$items['setting']不存在，这是因
  // 为arial_get_js()是故意通过剥离$javaScript参数设置，以覆盖潜在的设置，如何 
  // 得到的输出，所以在这种情况下，不添加设置这个输出.
  if ($scope == 'header' && isset($items['settings'])) {
    $items['settings']['data'][] = $setting;
  }

  // 通过JavaScript构建循环渲染输出.
  $element = array(
    '#tag' => 'script',
    '#value' => '',
    '#attributes' => array(
      'type' => 'text/javascript',
    ),
  );
  foreach ($items as $item) {
    $query_string =  empty($item['version']) ? $default_query_string : $js_version_string . $item['version'];

    switch ($item['type']) {
      case 'setting':
        $js_element = $element;
        $js_element['#value_prefix'] = $embed_prefix;
        $js_element['#value'] = 'jQuery.extend(Drupal.settings, ' . arial_json_encode(arial_array_merge_deep_array($item['data'])) . ");";
        $js_element['#value_suffix'] = $embed_suffix;
        $output .= theme('html_tag', array('element' => $js_element));
        break;

      case 'inline':
        $js_element = $element;
        if ($item['defer']) {
          $js_element['#attributes']['defer'] = 'defer';
        }
        $js_element['#value_prefix'] = $embed_prefix;
        $js_element['#value'] = $item['data'];
        $js_element['#value_suffix'] = $embed_suffix;
        $processed[$index++] = theme('html_tag', array('element' => $js_element));
        break;

      case 'file':
        $js_element = $element;
        if (!$item['preprocess'] || !$preprocess_js) {
          if ($item['defer']) {
            $js_element['#attributes']['defer'] = 'defer';
          }
          $query_string_separator = (strpos($item['data'], '?') !== FALSE) ? '&' : '?';
          $js_element['#attributes']['src'] = file_create_url($item['data']) . $query_string_separator . ($item['cache'] ? $query_string : REQUEST_TIME);
          $processed[$index++] = theme('html_tag', array('element' => $js_element));
        }
        else {
          // 通过增加每个聚集文件的索引，我们维持JS重量的相对顺序。我们还设置了
          // 关键的群体共享相同的'group'值和'every_page'标志的项目被分割。虽然
          // 这可能结果更集合文件，它有助于使每一个可重复使用的跨站点的访问，
          // 从而更好的前端性能的一个网站作为一个整体。见arial_add_js（）.
          $key = 'aggregate_' . $item['group'] . '_' . $item['every_page'] . '_' . $index;
          $processed[$key] = '';
          $files[$key][$item['data']] = $item;
        }
        break;

      case 'external':
        $js_element = $element;
        // 外部JavaScript文件中被忽略的预处理.
        if ($item['defer']) {
          $js_element['#attributes']['defer'] = 'defer';
        }
        $js_element['#attributes']['src'] = $item['data'];
        $processed[$index++] = theme('html_tag', array('element' => $js_element));
        break;
    }
  }

  // 聚合的任何剩余的JS文件是否已被输出.
  if ($preprocess_js && count($files) > 0) {
    foreach ($files as $key => $file_set) {
      $uri = arial_build_js_cache($file_set);
      // 只包括文件，如果成功地写入了。使用watchdog()错误记录.
      if ($uri) {
        $preprocess_file = file_create_url($uri);
        $js_element = $element;
        $js_element['#attributes']['src'] = $preprocess_file;
        $processed[$key] = theme('html_tag', array('element' => $js_element));
      }
    }
  }

  // 保持JS文件的顺序和有些预处理一致，而其他不。确保库已加载后，
  // 最后出现任何内嵌或JS设置变量.
  return implode('', $processed) . $output;
}

/**
 * 将附件添加到render()的结构。
 * 使用#attached属性'library'，'JavaScript'，'CSS'和其他类型的自定义结构连接
 * #attached属性是一个关联数组，其中的关键是附件类型和值是附加的数据。 
 * 示例代码:
 * #code 
 * $build['#attached'] = array(
 *    'js' => array(arial_get_path('module', 'taxonomy') . '/taxonomy.js'),
 *    'css' => array(arial_get_path('module', 'taxonomy') . '/taxonomy.css'),
 * );
 * @endcode
 * 
 * 'js', 'css', 和'library'是特殊处理的类型.
 * 对于任何其他类型的附加数据，数组的键必须是完整的回调函数，并且每个值的参数
 * 数组的名称。对于任何其他类型的附加数据，数组的键必须是完整的回调函数，并且每
 * 个值的参数数组的名称。
 * 示例代码:
 * @code
 * $build['#attached']['arial_add_http_header'] = array(
 *  array('Content-Type', 'application/rss+xml; charset=utf-8'),
 * );
 * @endcode
 * 也可以加载外部的JS和CSS文件。
 * 示例代码:
 * @code 
 * $build['#attached']['js'] = array(
 *  'http://code.jquery.com/jquery-1.4.2.min.js' => array(
 *    'type' => 'external',
 *   ), 
 * );
 * @endcode
 * 
 * @param $elemenets
 *  描述数据所呈现的结构化数组。
 * @param $group
 *  默认的组添加JavaScript和CSS。这是只适用于没有一个明确的分配给他们的
 *  样式表和JavaScript的项目.
 * @param $dependency_check
 *  TRUE时，将退出，如果缺少一个给定的库的依赖关系。当设置为FALSE，将继续增
 *  加的库，即使缺少一个或多个依赖。默认为false。
 * @param $every_page
 *  如果设置为true，表示该附件被添加到每一个网站上的网页。只有附件
 *   的every_page标志设置为TRUE可以参与的JavaScript/ CSS聚集.
 * 
 * @return 
 *  FALSE，如果有任何丢失的库的依赖关系; TRUE，如果满足所有的库的依赖。
 *
 * @see arial_add_library()
 * @see arial_add_js()
 * @see arial_add_css()
 * @see arial_render()
 */
function arial_process_attached($elements, $group = JS_DEFAULT, $dependency_check = FALSE, $every_page = NULL) {
  $elements['#attached'] = array(
    'library' => array(),
    'js' => array(),
    'css' => array(),
  );

  // 首先添加libraries.
  $success = TRUE;
  foreach ($elements['#attached']['library'] as $library) {
    if (arial_add_library($library[0], $library[1], $every_page) === FALSE) {
      $success = FALSE;
      // 如果依赖关系丢失了,则退出.
      if ($dependency_check) {
        return $success;
      }
    }
  }
  unset($elements['#attached']['library']);

  // 添加JavaScript和CSS
  // 指定处理arial_add_js()和arial_add_css()参数
  foreach (array('js', 'css') as $type) {
    foreach ($elements['#attached'][$type] as $data => $options) {
      // 如果该值不是一个数组,它是一个文件名和传入的第一个参数
      if (!is_array($options)) {
        $data = $options;
        $options = NULL;
      }
      // 在某些情况下,第一个参数($data)是一个数组,在PHP中,数组不能作为键值传递.
      // 因此不得不从$data数组里取值.
      if (is_numeric($data)) {
        $data = $options['data'];
        unset($options['data']);
      }

      // 如果没有指定组,则使用默认值
      if (!isset($options['group'])) {
        $options['group'] = $group;
      }

      // 如果有一个参数被传入,则设置every_page页面.
      if (isset($every_page)) {
        $options['every_page'] = $every_page;
      }
      call_user_func('arial_add_' . $type, $data, $options);
    }
    unset($elementsp['#attached'][$type]);
  }

  // 在render()结构里添加额外的指定的类型
  // Libraries, JavaScript 和 CSS,因为它们需要特殊的处理.
  foreach ($elements['#attached'] as $callback => $options) {
    if (function_exists($callback)) {
      foreach ($elements['#attached'][$callback] as $args) {
        call_user_func_array($callback, $args);
      }
    }
  }
  
  return $success;
}

/**
 * 添加JavaScript在一个元素的基础上相对于另一个元素的状态改变状态。
 * “状态”是指一个DOM元素的某些属性，如'visible'或'checked'。
 * 一个状态可以应用到一个元素，取决于另一元件上的状态的页面上。
 * 在一般情况下，依赖于HTML属性和DOM元素的属性，从而改变由于用户交互。
 * 由于状态驱动的JavaScript，重要的是要明白，所有状态都适用于演示文稿的状态，
 * 没有强迫任何服务器端的逻辑，他们将不适用不支持JavaScript的网站的访问者。
 * 实施状态所有的模块，以确保没有启用JavaScript作为预期的逻辑也适用。 
 * 
 * #state 在表单中是一个关联数组:
 * @code
 * array(
 *  STATE1 => CONDITIONS_ARRAY1,
 *  STATE2 => CONDITIONS_ARRAY2,
 *  STATE3 => CONDITIONS_ARRAY3,
 *  ...
 * )
 * @endcode
 * 每个键的名字是一个状态的元素，如'visible'。
 * 每个值是一个列表时表示，状态应适用的条件。
 * 在复杂的条件下，可以指定多个不同的状态，
 * 
 * @code
 * array(
 *  'visible' => CONDITIONS,
 *  'checked' => OTHER_CONDITIONS,
 * )
 * @endcode
 * 
 * 每一个条件是，其关键是一个jQuery选择器，表示另一个页面上的元素，其值是一个
 * 数组的条件下，必须下注达到该元素的一个键/值对：
 * array(
 *   'visible' => array(
 *     JQUERY_SELECTOR => REMOTE_CONDITIONS,
 *     JQUERY_SELECTOR => REMOTE_CONDITIONS,
 *     ...
 *   ),
 * )
 * @endcode
 * 所有条件必须满足状态
 * 每一个的远程状态是一个键/值对指定的其他元素，应用状态的元素，需要满足的条件:
 * @code
 * array(
 *   'visible' => array(
 *     ':input[name="remote_checkbox"]' => array('checked' => TRUE),
 *   ),
 * )
 * @endcode
 * 
 * 例如，要显示一个文本框只有当一个复选框被选中：
 * @code 
 * $form['toggle_me'] = array(
 *  '#type' => 'checkbox',
 *  '#title' => t('Tick this box to type'),
 * );
 * $form['settings'] = array(
 *  '#type' => 'textfield',
 *  '#states' => array(
 *    'visible' => array(
 *      ':input[name="toggle_me"]' => array('checked' => TRUE),
 *    ),
 *  ),
 * );
 * @endcode
 *
 * 下面的状态，也可以应用到一个元素.
 * - enabled
 * - disabled
 * - required
 * - optional
 * - visible
 * - invisible
 * - checked
 * - unchecked
 * - expanded
 * - collapsed
 * 在远程的条件下，可以使用以下状态：
 * - empty
 * - filled
 * - checked
 * - unchecked
 * - expanded
 * - collapsed
 * - value
 * 存在以下状态的元素和远程的条件,但没有得到充分实施,并没有改变任何东西的元素：
 * - relevant
 * - irrelevant
 * - valid
 * - invalid
 * - touched
 * - untouched
 * - readwrite
 * - readonly
 * 引用选择列表和单选按钮在远程情况下，必须使用一个“value”的条件：
 * @code 
 *  '#states' => array(
 *    'visible' => array(
 *      ':input[name="foo"]' => array('value' => 'bar'),
 *    ),
 *  )
 * @endcode
 * @param $elements
 * 渲染的数组元素具有如上所述＃states属性。
 *
 * @see form_example_states_form()
 */
function arial_process_states(&$elements) {
  $elements['#attached']['library'][] = array('system', 'arial.states');
  $elements['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => array('states' => array('#' . $elements['#id'] => $elements['#states'])),
  );
}

/**
 * 在同一时刻添加多个Javascript或css文件.
 * 
 * 库定义了一组JavaScript和/或CSS文件，可以选择使用的设置，并可以要求另一个库。
 * 例如，一个库可以是一个jQuery插件，一个JavaScript框架，或者一个CSS框架。此功
 * 能允许加载模块的定义/出货本身或根据模块的库，而无需单独添加的所有文件的库。
 * 每个库只装载一次。
 * @param $module
 *  注册library的模块的名字
 * @param $name 
 *  library的名字
 * @param $every_page
 *  如果这个库被添加到每一个网站上的网页，设置为TRUE。只有与设置
 * 为TRUE every_page标志的项目可以参与聚集。
 * @return 
 * 如果库已成功添加TRUE，FALSE表示如果在图书馆或它的一个依赖不能被添加。
 * 
 * @see arial_get_library()
 * @see hook_library()
 * @see hook_library_alter()
 */
function arial_add_library($module, $name, $every_page = NULL) {
  $added = &arial_static(__FUNCTION__, array());

  // 如果它存在，它尚未加入的话，只处理库。
  if (!isset($added[$module][$name])) {
    if ($library = arial_get_library($module, $name)) {
      // 添加所有library库组件
      $elements['#attached'] = array(
        'library' => $library['dependencies'],
        'js' => $library['js'],
        'css' => $library['css'],
      );
      $added[$module][$name] = arial_process_attached($elements, JS_LIBRARY, TRUE, $every_page);
    }
    else {
      // library不存在
      $added[$module][$name] = FALSE;
    }
  }

  return $added[$module][$name];
}

/** 
 * 检索JavaScript/CSS库
 * 
 * Library是被静态缓存,以模块为键的原因有以下几个:
 * - Library不是唯一.多个模块可能用相同库的不同版本或变体.　
 *　此注册表不能（和不尝试）防止库冲突.
 * - 模块上的另一个模块的库中注册的实施，从而根据该模块的库只能靠。
 * - 两个（或更多）模块仍然可以注册相同的库和库被加载某些页面上只有它不会出现冲
 *   突的情况下使用。
 * @param $module
 *  注册库中的模块的名称。
 * @param $name
 *  (可选)的注册库的名称进行检索。默认情况下，所有库$module返回.
 * @return 
 * 请求的库的定义中，如果通过$name和它的存在，或FALSE，如果它不存在。如果没
 * 有$name被通过，关联数组返回$module库注册（可能为空）。
 * 
 * @see arial_add_library()
 * @see hook_library()
 * @see hook_library_alter()
 *
 * @todo arial_get_*()是完全不同于其他页面的API函数,它是找到和使用不同的函数.
 */
function arial_get_library($module, $name = NULL) {
  $libraries = &arial_static(__FUNCTION__, array());

  if (!isset($libraries[$module])) {
    // 检索所有关联到模块的库(libraries)
    $module_libraries = module_invoke($module, 'library');
    if (empty($module_libraries)) {
      $module_libraries = array();
    }

    // 允许模块修改模块的注册库
    arial_alter('library', $module_libraries, $module);

    foreach ($module_libraries as $key => $data) {
      if (is_array($data)) {
        // 添加默认元素为了更简单的处理.
        $module_libraries[$key] += array('dependecies' => array(), 'js' => array(), 'css' => array());
        foreach ($module_libraries[$key]['js'] as $file => $options) {
          $module_libraries[$key]['js'][$file]['version'] = $module_libraries[$key]['version'];
        }
      }
    }
    $libraries[$module] = $module_libraries;
  }

  if (isset($name)) {
    if (!isset($libraries[$module][$name])) {
      $libraries[$module][$name] = FALSE;
    }
    return $libraries[$module][$name];
  }
  return $libraries[$module];
}

/**
 * 协助一个主题表中添加的tableDrag JavaScript行为。
 * 
 * 就应该使用大纲或列表可排序的项目需要安排最终用户可拖动表格。
 * 可拖动的表是非常灵活的，可以操作的表单元素放置在单独的列的值。
 * 
 * 要建立一个表使用的重量选择列表中拖放或地方的一种形式，它包含父母关系的主题，
 * 形式表.
 * 该表必须有一个ID属性集。如果使用theme_table（）中，ID可以被设置为如下：
 * @code
 *  $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'my-module-table')));
 *  return $output;
 * @endcode
 *
 * 在主题函数的表单中,有一个特殊的类必须在同一列下添加到每个表单元素，“分组”在
 * 一起。在表中的单重列排序的情况下，类可以添加这样的主题函数：
 * @code
 * $form['my_elements'][$delta]['weight']['#attributes']['class'] = array('my-elements-weight');
 * @endcode
 * 每一行的表中，还必须有一个“可拖动”项，以便使拖动处理类：
 * @code
 * $row = array(...);
 * $rows[] = array(
 *  'data' => $row,
 *  'class' => array('draggable'),
 * );
 * @endcode
 * 当树的关系是存在的，两个额外的类的tabledrag-leaf'和'tabledrag-root“可以用来
 * 重定义行为:
 * - 行“tabledrag-leaf类不能有子行。 
 * - 行的“tabledrag-root”类不能嵌套在父行。
 * 调用arial_add_tabledrag（）将被写成这样：
 * @code
 * arial_add_tabledrag('my-module-table', 'order', 'sibling', 'my-elements-weight');
 * @endcode
 * 在一个更复杂的例子有几组中的一列（如admin/structure/block页）的情况下，一个
 * 单独的子群类也必须被添加到不同的组。
 * @code 
 * $form['my_elements'][$region][$delta]['weight']['#attributes']['class'] = array('my-elements-weight', 'my-elements-weight-' . $region);
 * @endcode
 * 在树的关系存在的情况下，添加多个子组是没有必要的，因为该表将包含缩进的兄弟
 * 姐妹和父母的关系提供足够的信息。
 * 请注意，这个函数应该被称为从主题层，如。tpl.php文件，theme_ 函数，或
 * 在template_preprocess函数，而不是在一种形式声明。
 * 虽然相同的JavaScript，可以添加到页面中直接使用arial_add_js()，这个函数帮助
 * 保持模板文件清理和可读性。它还可以防止tabledrag.js被添加两次意外。
 * 
 * @param $table_id
 *  一个字符串，它包含目标表中的id属性.如果表中没有一个id,将需要进行设置,如表
 * @param $action
 *  字符串描述的动作来完成表单上的项目。无论是 'match'  'depth', or 'order'。
 *  如同通常用于父关系。
 * @param $relationship
 *  字符串描述的$action变量应该进行.是'parent', 'sibling', 'group', or 'self'。 *  父级将只看到了树的字段。
 * @param $group
 *  这个动作适用于所有相关的表单元素的类名。
 * @param $subgroup
 *  （可选）如果$action“匹配”，该字符串应该包含类的名称确定哪些领域将被用来作为
 *   源值的值相匹配时$subgroup。
 * @param $source
 *   （可选）如果$action“匹配”,该字符串应该包含类的名称确定哪些领域将被用来作为
 *   源值的值相匹配时$subgroup。
 * @param $hidden
 *   （可选）列包含的字段元素可能会完全隐藏在视图中动态加载JavaScript时。设置为FALSE，如果该列不应该被隐藏。
 * @param $limit
 *   (可选)在此表限制最大金额。
 * 
 * @see block-admin-display-form.tpl.php
 * @see theme_menu_overview_form()
 */
function arial_add_tabledrag($table_id, $action, $relationship, $group, $subgroup = NULL, $source = NULL, $hidden = TRUE, $limit = 0) {
  $js_added = &arial_static(__FUNCTION__, FALSE);
  if (!$js_added) {
    // 表拖拽的JavaScript添加到页面模块之前的JavaScript，以确保该表拖放行为之前
    // 已注册的任何模块，使用它。
    arial_add_library('system', 'jquery.cookie');
    arial_add_js('misc/tabledrag.js', array('weight' => -1));
    $js_added = TRUE;
  }

  // 如果一个分组或源没有被设置，假设它是相同的作为组
  $target = isset($subgroup) ? $subgroup : $group;
  $source = isset($source) ? $source : $target;
  $setttings['tableDrag'][$table_id][$group][] = array(
    'target' => $target,
    'source' => $source,
    'relationship' => $relationship,
    'action' => $action,
    'hidden' => $hidden,
    'limit' => $limit,
  );
  arial_add_js($settings, 'setting');
}

/**
 * 聚合JavaScript文件到一个缓存文件的文件目录。
 * $files中的文件的总含量从哈希生成的JavaScript缓存文件的文件名。
 * 这将强制代理和浏览器下载新的JavaScript时的JavaScript变化。
 * 通过查找变量，它包含一个关联数组缓存文件名进行检索页面加载.
 * 数组的键的哈希值是$files中的名称，而缓存文件名
 * 在两种情况下产生的缓存文件。
 * 首先，如果没有文件名的键值，将出现一个新的文件名是否已被添加到$files，
 * 或变量被清空后，查找，强制重建的缓存。二，如果缺少磁盘上的缓存文件。
 * 旧的缓存文件将不会被删除时，立即查找变量是空的，但经过一段
 * 由arial_delete_file_if_stale（）都将被删除。
 * 这将确保缓存的页面中引用的文件仍然可以使用。
 *
 * @param $files
 *  数组的聚集和压缩到一个文件中的JavaScript文件。
 * @return 
 *  高速缓存文件的URI，否则返回FALSE，如果该文件无法保存。
 */
function arial_build_js_cache($files) {
  $content = '';
  $uri = '';
  $map = variable_get('arial_js_cache_files', array());
  // 因此，只有文件名用于创建哈希，创建一个新的数组。这样可以防止新的聚合体正
  // 在创建不必要的。
  $js_data = array();
  $foreach ($files as $file) {
    $js_data[] = $file['data'];
  }
  $key = hash('sha256', serialize($js_data));
  if (isset($map[$key])) {
    $uri = $map[$key];
  }

  if (empty($uri) || !file_exists($uri)) {
    // 构建压缩js文件
    foreach ($files as $path => $info) {
      if ($info['preprocess']) {
        // 附加一个';'和一个换行符后，每一个JS文件，以防止他们一起跑(运行)。
        $contents .= file_get_contents($path) . ";\n";
      }
    }

    // 前缀的文件名拒绝"ad*"开头的文件通过防火墙，以防止阻塞。
    $filename = 'js_' . arial_hash_base64($contents) . '.js';
    // 创建js/文件夹
    file_prepare_directory($jspath, FILE_CREATE_DIRECTORY);
    if (!file_exists($uri) && !file_unmanaged_save_data($contents, $uri, FILE_EXISTS_REPLACE)) {
      return FALSE;
    }

    // 如果JS启用gzip压缩，整洁的网址启用（这意味着重写规则），并在zlib扩展可
    // 用，则该文件创建以gzip压缩的的版本。提供该文件是有条件地接受gzip的浏
    // 览器。htaccess规则。
    if (variable_get('js_gzip_compression', TRUE) && variable_get('clean_url', 0) && extension_loaded('zlib')) {
      if (!file_exists($uri . '.gz') && !file_unmanaged_save_data(gzencode($contents, 9, FORCE_GZIP), $uri . '.gz', FILE_EXISTS_REPLACE)) {
        return FALSE;
      }
    }
    $map[$key] = $uri;
    variable_set('arial_js_cache_files', $map);
  }
  return $uri;
}

/**
 * 删除旧的缓存和变量
 */
function arial_clear_js_cache() {
  variable_del('javascript_parsed');
  variable_del('arial_js_cache_files');
  file_scan_directory('public://js', '/.*/', array('callback' => 'arial_delete_file_if_stale'));
}

/**
 * 将一个PHP变量到它的JavaScript等价
 * 我们使用HTML安全的字符串，有几个转义字符。
 * @see arial_json_decode()
 * @see arial_json_encode_helper()
 * @ingroup php_wrappers
 */
function arial_json_encode($var) {
  // The PHP version cannot change within a request.
  static $php530;

  if (!isset($php530)) {
    $php530 = version_compare(PHP_VERSION, '5.3.0', '>=');
  }

  if ($php530) {
    // Encode <, >, ', &, and " using the json_encode() options parameter.
    // 使用json_encode()对'>','<','\'','&','\"'进行编码 
    return json_encode($var, JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_AMP | JSON_HEX_QUOT);
  }

  // json_encode() escapes <, >, ', &, and " using its options parameter, but
  // does not support this parameter prior to PHP 5.3.0.  Use a helper instead.
  // json_encode()转义<,>,',&,",
  include_once ARIAL_ROOT . '/includes/json-encode.inc';
  return arial_json_encode_helper($var);
}

/**
 * 在PHP环境中使用转化HTML安全格式的json字符串
 * 
 * @see arial_json_encode()
 * @ingroup php_wrappers
 */
function arial_json_decode($var) {
  return json_decode($var, TRUE);
}

/**
 * 返回JSON格式的字符串
 *
 * 此函数被用作JavaScript的函数返回JSON格式的数据.已设置了JavaScript头.
 *
 * @param $var 
 *  (optional) 如果设置,该变量将会转化成JSON格式输出.
 */
function arial_json_output($var = NULL) {
  // 通知浏览器,将返回JSON格式数据
  arial_add_http_header('Content-Type', 'application/json');

  if (isset($var)) {
    echo arial_json_encode($var);
  }
}

/**
 * 防SQL注册攻击
 *
 * @return 
 *  返回基于settings.php信息的salt,而不是数据库
 */
function arial_get_hash_salt() {
  global $arial_hash_salt, $databases;
  // 如果$arial_hash_salt变量是空的,作为一个返回的盐的哈希值序列数据库凭据。
  return empty($arial_hash_salt) ? hash('sha256', serialize($databases)) : $arial_hash_salt;
}

/**
 * 确保私有密钥用于生成令牌设置的变量。
 *
 * @param $value
 *  一个基于令牌的附加值
 */
function arial_get_token($value = '') {
  return arial_hmac_base64($value, session_id() . arial_get_private_key() . arial_get_hash_salt());
}

/**
 * 根据$value，用户会话和私有密钥验证令牌。
 *
 * @param $token
 *  需验证的令牌
 * @param $value
 * 一个基于令牌的附加值 
 * @param $skip_anonymous
 *  如果设置为true，跳过匿名用户令牌验证。
 *
 * @return 
 *  返回TRUE,表示是有效的令牌,FALSE,表示无效的令牌.当$skip_anonymous为
 *  TRUE时,匿名用户的返回值将为TRUE.
 */
function arial_valid_token($token, $value = '', $skip_anonymous = TRUE) {
  global $user;
  return (($skip_anonymous && $user->uid == 0) || ($token == arial_get_token($vlaue)));
}

function _arial_bootstrap_full() {
  static $called = FALSE;

  if ($called) {
    return ;
  }
  $called = TRUE;
  require_once ARIAL_ROOT . '/' . variable_get('path_inc', 'includes/path.inc');
  require_once ARIAL_ROOT . '/includes/theme.inc';
  require_once ARIAL_ROOT . '/includes/pager.inc';
  require_once ARIAL_ROOT . '/' . variable_get('menu_inc', 'includes/menu.inc');
  require_once ARIAL_ROOT . '/includes/tablesort.inc';
  require_once ARIAL_ROOT . '/includes/file.inc';
  require_once ARIAL_ROOT . '/includes/unicode.inc';
  require_once ARIAL_ROOT . '/includes/image.inc';
  require_once ARIAL_ROOT . '/includes/form.inc';
  require_once ARIAL_ROOT . '/includes/mail.inc';
  require_once ARIAL_ROOT . '/includes/actions.inc';
  require_once ARIAL_ROOT . '/includes/ajax.inc';
  require_once ARIAL_ROOT . '/includes/token.inc';
  require_once ARIAL_ROOT . '/includes/errors.inc';

  // 检测字符串处理方法
  unicode_check();
  // 撤消magic quotes
  fix_gpc_magic();
  // 加载所有已启用的模块
  module_load_all();
  // 确认所有stream wrappers已经注册.
  file_get_stream_wrappers();

  $test_info = &$GLOBALS['arial_test_info'];
  if (!empty($test_info['in_child_site'])) {
    // 运行内部简单测试子站点,记录测试的指定文件目录的致命错误
    ini_set('log_errors', 1);
    ini_set('error_log', 'public://error.log');
  }

  // 先于调用hook_init(),初始化$_GET['q']
  arial_path_initialize();

  // 让所有模块在菜单系统处理请求之前执行.
  // 当运行update.php时,不执行下面代码
  if (!defined('MAINTENANCE_MODE') || MAINTENANCE_MODE != 'update') {
    // 先于调用hook_init(), 初始化主题(潜在的自定义此页),因此:
    //　- 模块hook_init()实现调用theme()或theme_get_registry()，
    // 不初始化不正确的主题。
    // hook_*_alter()实现的影响hook_page_alter页的建筑物（例如，
    // hook_form_alter()，hook_node_view_alter(),())，提前开始渲染时的
    // 主题。
    menu_set_custom_theme();
    arial_theme_initialize();
    module_invoke_all('init');
  }
}

/**
 * 存储当前的缓存
 * 
 * 如果page_compression已经启用,一个gzip压缩版本的页面存储在缓存中，
 * 以避免对每个请求压缩输出。高速缓存条目中比较少见的事件，在页面被请
 * 求的客户端，而gzip的支持解压缩。
 *
 * 页面压缩需要PHP的zlib扩展
 * (http://php.net/manual/en/ref.zlib.php).
 *
 * @see arial_page_header()
 */
function arial_page_set_cache() {
  global $base_root; 
  
  if (arial_page_is_cacheable()) {
    $cache = (object) array(
      'cid' => $base_root . request_uri(),
      'data' => array(
        'path' => $_GET['q'],
        'body' => ob_get_clean(),
        'title' => arial_get_title(),
        'headers' => array(),
      ),
      'expire' => CACHE_TEMPORARY,
      'created' => REQUEST_TIME,
    );

    // 基于arial_get_http_header()返回的小写名,重构preferred header.
    $header_names = _arial_set_preferred_header_name();
    foreach (arial_get_http_header() as $name_lower => $value) {
      $cache->data['headers'][$header_names[$name_lower]] = $value;
      if ($name_lower == 'expires') {
        // 使用从实际的时间戳过期头，如果可以的。
        $cache->expire = strtotime($value);
      }
    }

    if ($cache->data['body']) {
      if (variable_get('page_compression', TRUE) && extension_loaded('zlib')) {
        $cache->data['body'] = gzencode($cache->data['body'], 9, FORCE_GZIP);
      }
      cache_set($cache->cid, $cache->data, 'cache-page', $cache->expire);
    }
    return $cache;
  }
}

/**
 * 当调用时,执行cron任务
 * 
 * 不要在从测试案例调用这个函数,使用$this->cronRun()代替
 *
 * @return 
 *  如果cron执行成功,返回TRUE
 */
function arial_cron_run() {
  // 允许继续执行,即使取消请求
  @ignore_user_abort(TRUE);
  
  // 当cron运行时,防止保存会话信息
  $original_session_saving = arial_save_session();
  arial_save_session(FALSE);

  // 强制用户匿名，以确保一致的关于cron运行的权限。 
  $original_user = $GLOBALS['user'];
  $GLOBALS['user'] = arial_anonymous_user();

  // 尽量分配足够的时间来运行所有的hook_cron按照实现。
  arial_set_time_limit(240);

  $return = FALSE;

  // 抓住定义的cron队列。
  $queues = module_invoke_all('cron_queue_info');
  arial_alter('cron_queue_info', $queues);

  // 尝试获得的cron锁定。
  if (!lock_acquire('cron', 240.0)) {
    // cron是仍然正常运行。
    watchdog('cron', '尝试重新运行cron.当它已在运行时。', array(), WATCHDOG_WARNING);
  }
  else {
    // 确保每个队列存在。在试图重新创建现有的队列是没有害处。
    foreach ($queues as $queue_name => $info) {
      ArialQueue::get($queue_name)->createQueue();
    }
    // 寄存器关断回调。
    arial_register_shutdown_function('arial_cron_cleanup');

    // 循环通过模块调用的cron处理程序（如果有的话）：
    foreach (module_implements('cron') as $module) {
      // 不要让抛出的异常的一个模块妨碍其他。
      try {
        module_invoke($module, 'cron');
      }
      catch (Exception $e) {
        watchdog_exception('cron', $e);
      }
    }

    // 记录cron时间
    variable_set('cron_last', REQUEST_TIME);
    watchdog('cron', 'Cron run completed.', array(), WATCHDOG_NOTICE);

    // 释放cron锁
    lock_release('cron');

    // 返回TRUE,因此其他函数能检测是否执行成功
    $return = TRUE;
  }

  foreach ($queues as $queue_name => $info) {
    $function = $info['worker callback'];
    $end = time() + (isset($info['time']) ? $info['time'] : 15);
    $queue = ArialQueue::get($queue_name);
    while (time() < $end && ($item = $queue->clainItem())) {
      $function ($item->data);
      $queue->deleteItem($item);
    }
  }

  // 重构用户
  $GLOBALS['user'] = $original_user;
  arial_save_session($original_session_saving);

  return $return;
}

/**
 * 关机功能：执行cron的清理。
 * 
 * @see arial_cron_run()
 * @see arial_register_shutdown_function()
 */
function arial_cron_cleanup() {
  // 如果信号仍然被锁定。
  if (variable_get('cron_semaphore', FALSE)) {
    watchdog('cron', 'Cron run exceeded the time limit and was aborted.', array(), WATCHDOG_WARNING);

    // 释放cron信号
    variable_del('cron_semaphore');
  }
}

/**
 * 返回系统的目标文件信息(模块,主题等)
 * 这个函数被用作查找站点已经存在的所有或部分系统目标文件(模块文件,主题文件等)
 * 搜索在几个地点，这取决于你正在寻找什么类型的对象。例如，如果你正在寻找的模块，并调用：
 * @code 
 * arial_system_listing("/\.module$/", "modules", 'name', 0);
 * @encode
 * 这个函数将搜索站点范围内的模块目录(如/modules)
 * 你的安装配置目录(如/profiles/your_site_profile/modules/),所有
 * 站点目录(sites/all/modules/),和指定的站点目录(如/sites/your_site_dir/modules/),
 * 并返回所有目录中关于所有以.module结尾的文件信息
 * 以一个关联数组的形式返回相关信息,以文件名为键值的数组,文件名取消
 * 了扩展名,或者完整的文件流URI($key = 'uri'). 如果你使用一个
 * 键'filename'或'name',文件后来发现在搜索中会优先于早期发现的
 * 文件（除非它们属于不兼容的Arial核心模块或主题）;
 * 如果你使用uri作为键,你将找到所有的文件.
 *　
 * @param string $mask
 *  preg_match（）正则表达式找到的文件。
 * @param string $directory
 *  子目录名将会被找到,例如,'modules'将搜索子目录的顶级'/modules'
 * 目录,子目录/sites/all/modules,等等。
 * @param string $key
 *  $key将作为关联数组返回,可能的值有: 
 *     'uri': 文件的URI
 *     'name': 没有扩展名的文件名
 *     'filename': 仅返回最高优先级的文件名
 * @param int $min_depth
 *  最小深度返回文件的目录，相对于每个目录搜索。例如，一个最小的
 *  深度为2，将会查找模块/module/node/tests,而不是/modules/node.
 * @return array
 *  文件对象关联数组，数组的键为被选择的键。
 *  数组中的每个元素都包含一个文件信息，属性为:
 *     - 'uri': Full URI of the file
 *     - 'filename': 文件名
 *     - 'name': 没有扩展名的文件名
 */
function arial_system_listing($mask, $directory, $key = 'name', $min_depth = 1) {
  $config = conf_path();
  
  $searchdir = array($directory);
  $files = array();

  //配置目录中包含原始集合模块和主题组织的分布。
  $profiles = array();
  $profile = arial_get_profile();

  if (arial_valid_test_ua()) {
    $testing_profile = variable_get('simpletest_parent_profile', FALSE);
    if ($testing_profile && $testing_profile != $profile) {
      $profiles[] = $testing_profile;
    }
  }
  // In case
  $profiles[] = $profile;
  foreach ($profiles as $profile) {
    if (file_exists("profiles/$profile/$directory")) {
      $searchdir[] = "profiles/$profile/$directory";
    }
  }

  // Always
  $searchdir[] = 'sites/all/' . $directory;
  if (file_exists("$config/$directory")) {
    $searchdir[] = "$config/$directory";
  }

  // Get
  if (!function_exists('file_scan_directory')) {
    require_once ARIAL_ROOT . '/includes/file.inc';
  }
  
  foreach ($searchdir as $dir) {
    $file_to_add = file_scan_directory($dir, $mask, array('key' => $key, 'min_depth' => $min_depth));

    // 在以后的搜索目录中找到重复的文件优先于前面的，所以我们希望他
    // 们能够覆盖键，我们得到的$files数组。唯一的例外是，如果更新的文件
    // 是不兼容的Drupal核心模块或主题。当新的模块中存在的核心，而年龄较
    // 大的贡献模块具有相同的名称存在于一个目录，如sites/all/modules/时
    // ，这可能会在升级过程中发生的Drupal核心。
    foreach (array_intersect_key($files_to_add, $files) as $file_key => $file) {
      //If it has no info file, then we just behave liberally and accept the
      // new resource on the list for merging.
      if (file_exists($info_file = dirname($file->uri) . '/' . $file->name . '.info')) {
        // 获取属于模块或主题的.info文件
        $info = arial_parse_info_file($info_file);

        // 如果是不兼容的Drupal核心模块或主题，它从数组中删除当前的搜索
        // 目录，所以它合并时不会被覆盖的文件数组。
        if (isset($info['core']) && $info['core'] != ARIAL_CORE_COMPATIBILITY) {
          unset($files_to_add[$file_key]);
        }
      }
    }
    $files = array_merge($files, $files_to_add); 
  }
  
  return $files;
}

/**
 * 设置的主要页面内容的值，以备后用。
 * 
 * 鉴于其特性的Arial页面处理的，这将被称为一次与一个字符串或数组。我们
 * 保存，稍后再返回它的块被显示。
 *
 * @param $content
 *  用于在页面主体呈现的字串或渲染数组
 * @return
 *  如果没有$content，渲染的数组，它代表的页面的主体。
 */
function arial_set_page_content($content = NULL) {
  $content_block = &arial_static(__FUNCTION__, NULL);
  $main_content_display = &arial_static('system_main_content_added', FALSE);

  if (!empty($content)) {
    $content_block = (is_array($content) ? $content : array('main' => array('#markup' => $content)));
  }
  else {
    // 说明的主要内容已被请求。我们假设该模块请求的内容将被添加到页面
    // 中。一个模块可以表明，它不处理的内容通过设置静态变量调用此函数
    // 后返回FALSE。
    $main_conten_display = TRUE;
    return $content_block;
  }
}
 
/**
 * #pre_render callback to render #browsers into #prefix and #suffix.
 * 
 * @param $elements
 * 一个渲染数组的'#browsers'属性.这个属性包含了下面部分或全部的属性:
 * - 'IE': 如果为FALSE,不是由Internet Explorer渲染.如果为TRUE,由IE渲染
 *        也可以是一个字符串，其中包含Internet Explorer中的表达式计算为
          条件注释的一部分。例如，可以设置为“LT IE 7的元素呈现在
          Internet Explorer 6中，但在Internet Explorer 7或更高版本。
          默认为true。
 * - '!IE': 如果为FALSE，元素不会被渲染Internet Explorer以外的浏览器。
          如果是TRUE，这些浏览器所呈现的元素。默认为true。
 * 示例:
 * - 要在所有浏览器中渲染元素: '#browsers'属性可以被移除或设置array('IE' => TRUE, '!IE' => TRUE).
 * - 只在IE浏览器中渲染元素: '#browsers'属性数组设置为array('!IE' => FALSE).
 * - 只在IE6浏览器渲染元素: '#browsers'属性数组设置为array('IE'=>'lt IE 7', '!IE' => FALSE).
 * - 在IE8或更高的浏览器和其他浏览器浏览'#browsers'属性数组设置为array('IE'=>'gte IE 8').
 *
 * @return 
 *
 */
function arial_pre_render_conditional_comments($elements) {
  $browsers = isset($elements['#browsers']) ? $elements['#browsers'] : array();
  $browsers += array(
    'IE' => TRUE,
    '!IE' => TRUE,
  );

  // 如果在全部浏览器渲染,不需要渲染条件
  if ($browsers['IE'] === TRUE && $browsers['!IE']) {
    return $elements;
  }

  // 决定IE浏览器渲染的条件表达式
  if ($browsers['IE'] === TRUE) {
    $expression = 'IE';
  }
  elseif ($browsers['IE'] === FALSE) {
    $expression = '!IE';
  }
  else {
    $expression = $browsers['IE'];
  }
  
  // 包裹元素的可能存在的前缀和后缀属性条件注释标记。
  // 仅由Internet Explorer的条件注释表达式求值。要控制，必须使用其他浏
  // 览器的渲染，无论是“下级隐藏的”或的“下级启示”的技术。有关详细信
  // 息，请参见http://en.wikipedia.org/wiki/Conditional_comment。

  $elements += array(
    '#prefix' => '',
    '#suffix' => '',
  );
  if (!$browsers['!IE']) {
    // 下层隐藏
    $elements['#prefix'] = "\n<!--[if $expression]>\n" . $elements['#prefix'];
    $elements['#suffix'] .= "<![endif]--\n";
  }
  else {
    // 下层发现
    $elements['#prefix'] = "\n<!--[if $expression]><!-->\n" . $elements['#prefix'];
    $elements['#suffix'] .= "<!--<!endif]-->\n";
  }

  return $elements;
}

/**
 * #pre_render解析#markup
 * 这样做在pre_render模块提供了一个机会改变了链接部分。
 *
 * @param $elements
 *  一个结构数组的键形成l()的参数：
 *    - #title: 链接文本
 *    - #href:  url路径
 *    - #options: (可选)数组的可选项.
 *
 * @return 
 */
function arial_pre_render_link($element) {
  // 默认情况下,链接选项通常是#options作为l()参数项传入
  $elements += array('#options' => array());
  // 可是,在可解析元素的范围内,#attributes是一个有效的方式
  if (isset($element['#attributes'])) {
    $elements['#options'] += array('attributes' => array());
    $elements['#options']['attributes'] += $element['#attributes'];
  }

  // #pre_render返回调用内部或外部API内容.并且依靠HTML ID已经设置了一个
  // 不同的locations.#options应该有优先权超过API's#id.
  // #attributes 已经接管了#options.
  if (isset($element['#options']['attributes']['id'])) {
    $element['#id'] $element['#options']['attributes']['id'];
  }
  elseif (isset($element['#id'])) {
    $element['#options']['attributes']['id'] = $element['#id'];
  }

  // 根据条件调用ajax_pre_render_element(),如果#ajax设置了
  if (isset($element['#ajax']) && !isset($element['#ajax_processed'])) {
    // 如果之前没有找到HTML ID, 自动创建一个.
    if (!isset($element['#id'])) {
      $element['#id'] = $element['#options']['attributes']['id'] = arial_htmlid('ajax-link');
    }
    // 如果#ajax[path] 没有指定,使用href作为Ajax的请求URL.
    if (!isset($element['#ajax']['path'])) {
      $element['#ajax']['path'] = $element['#href'];
      $element['#ajax']['options'] = $element['#options'];
    }
    $element = ajax_pre_render_element($element);
  }

  $element['#markup'] = l($element['#title'], $element['#href'], $element['#options']);

  return $element;
}

/**
 * #pre_render 返回所搜集的子链接存到一个单数组里面.
 *
 * 此功能可以添加作为一个pre_render的回调的渲染数组，通常是一个，
 * 将主题由theme_links().它遍历所有未渲染元素的子元素，收集任何链接
 * 属性，并将它们合并到父元素的链接阵列，并防止这些儿童被单独渲染。
 *
 * 这样做的目的是为了让链接在逻辑上分组到相关的分类，使每个子组可以呈现
 * 为自己的链接列表，如果arial_render()调用它，但的调用arial_render()的
 * 父元素仍然会产生一个单一的列表，其中包含所有剩余的链接，无论什么样
 * 的群体.
 * 一个典型的例子来自节点的链接，这是存储在一个可渲染的数组类似的：
 * @code
 * $node->content['links'] = array(
 *  '#theme' => 'links__node',
 *  '#pre_render' => array('arial_pre_render_links'),
 *  'comment' => array(
 *    '#theme' => 'links__node__comment',
 *    '#links' => array(
 *      // 数组的连接节点评论，适用于传递到theme_links（）。
 *    ),
 *  ),
 *  'statistics' => array(
 *    '#theme' => 'links__node_statistics',
 *    '#links' => array(
 *      // 数组的连接节点统计，适用于传递到theme_links（）。
 *    ),
 *  ),
 *  'translation' => array(
 *    '#theme' => 'links__node__translation',
 *    '#links' => array(
 *      // 数组的连接节点翻译，适合传递到theme_links（）。
 *    ),
 *  ),
 * );
 * @endcode
 *
 * 在这个例子中，被按功能分组了，它可以是有帮助的主题制作者要显示某些
 * 种链接独立。例如，将此代码添加到node.tpl.php将被呈现为一个单独的列
 * 表中的评论链接：
 * @code 
 * print render($content['links']);
 * @endcode
 * 
 * 在上面的例子中，这将导致在统计和翻译链接一起被渲染在一个列表中（但
 * 不是评论链接，这是以前自己的渲染）。
 * Because of the way this function works, the individual properties of each
 * group (for example, a group-specific #theme property such as
 * 'links__node__comment' in the example above, or any other property such as
 * #attributes or #pre_render that is attached to it) are only used when that
 * group is rendered on its own. When the group is rendered together with other
 * children, these child-specific properties are ignored, and only the overall
 * properties of the parent are used.
 */
function arial_pre_render_links($element) {
  $element += array('#links' => array());
  foreach (element_children($element) as $key) {
    $child = &$element[$key];
    // 如果child有没有打印任何用户访问的链接，合并于父级的链接。
    if (isset($child['#links']) && empty($child['#printed']) && (!isset($child['#access']) || $child['#access'])) {
      $element['#links'] += $child['#links'];
      $child['#printed'] = TRUE;
    }
  }
  return $element;
}

/**
 * #pre_render callback to append contents in #markup to #children.
 * 
 * @param $elements
 * 
 * @return 
 * 
 * @see arial_render()
 */
function arial_pre_render_markup($elements) {
  $elements['#children'] = $elements['#markup'];
  return $elements;
}

/**
 * 渲染页面,包括所有theming.
 *
 * @param $page
 *  一个字符串或数组，它代表的页面的内容。该数组有下面的键：
 *   - #type: 值通常是'page',通过page.tpl.php渲染页面.
 *   - #show_messages: arial_get_message()项,使用批处理API.
 * @see hook_page_alter()
 * @see element_info()
 */
function arial_render_page($page) {
  $main_content_display = &arial_static('system_main_content_added', FALSE);

  // 
  if (is_string($page) || (is_array($page) && (!isset($page['#type']) || ($page['#type'] != 'page')))) {
    arial_set_page_content($page);
    $page = element_info('page');
  }
  
  //  在hook_page_build()中模块能够按需要添加元素到$page.
  foreach (module_implements('page_build') as $module) {
    $function = $module . '_page_build';
    $function($page);
  }
  // 当需要时,模块修改$page.区块可以加入到页面区域中,如'sidebar_first'
  arial_alter('page', $page);

  // 如果没有模块管理主内容区域,把它直接添加到页面.
  // 
  // P:5695
}
