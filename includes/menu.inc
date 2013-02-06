<?php

function menu_get_item($path = NULL, $router_item = NULL) {
  $router_items = &arial_static(__FUNCTION__);
  if (!isset($path)) {
    $path = $_GET['q']; 
  }
}

