<?php
/**
 * @file
 * 处理请求的主入口
 * 
 * 所有Arial代码都基于GNU通用公共许可证发布。
 */

/**
 * Arial 请求主入口
 */
define ('ARIAL_ROOT', getcwd());

//require_once ARIAL_ROOT . '/includes/bootstrap.inc';
require_once"ARIAL_ROOT.'/include/cache.inc'";
echo ARIAL_ROOT;
echo "<br />这里是Arial系统请求的主入口";
