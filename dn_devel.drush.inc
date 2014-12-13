<?php

/**
 * @file
 * Drush integration for the dn_devel module.
 */

/**
 * Implements hook_drush_command().
 */
function dn_devel_drush_command() {
  $items['dn_devel-generate-template'] = array(
    'description' => dt('Generate template for specify view'),
    'arguments' => array(
      'name' => dt('The view name'),
    ),
    'aliases' => array('dnt'),
    'required-arguments' => 1,
  );
  return $items;
}

/**
 * A command callback.
 */
function drush_dn_devel_generate_template($name) {
  $path = drupal_get_path('module', 'dn_devel');
  $name = str_replace('_', '-', $name);
  
  $views = file_get_contents($path . '/templates/views-view.tpl.php');
  $unformatted = file_get_contents($path . '/templates/views-view-unformatted.tpl.php');
  print_r($unformatted);
  $theme_path = drupal_get_path('theme', 'md_frexy');
  $destinaton = $theme_path . '/template/views/' . $name;
  drupal_mkdir($destinaton);
  
  // Write file
  file_put_contents($destinaton . "/views-view--{$name}.tpl.php", $views);
  file_put_contents($destinaton . "/views-view-unformatted--{$name}.tpl.php", $unformatted);
  file_put_contents($destinaton . "/views-view-fields--{$name}.tpl.php", '');
  
  drush_log(dt('Generate.'), 'ok');
}
