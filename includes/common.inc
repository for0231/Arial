<?php

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
}
