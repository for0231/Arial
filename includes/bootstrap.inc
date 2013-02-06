<?php
require 'menu.inc';

function &arial_static($name, $default_value = NULL, $reset = FALSE) {
  static $data = array(), $default = array();
}
