<?php

/** 
 * @file
 * 启动基于浏览器安装Arial的界面
 */

/**
 * Arial安装目录
 */
define('ARIAL_ROOT', getcwd());

/**
 * 启用Arial安装模式的全局标志
 */
define('MAINTENANCE MODE', 'install');

// PHP版本必须大于5.3.0,否则退出安装
if (version_compare(PHP_VERSION, '5.3.0') < 0 ) {
  print '你的PHP版本太低了，Arial环境至少需要PHP 5.3.0，请查看Arial系统<a href="http://fk.og">需求</a>。';
  exit;
}

// 转入系统安装代码
