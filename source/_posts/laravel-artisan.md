---
title: Artisan 控制台
top: 0
date: 2018-08-28 12:00:32
categories: PHP
tags:
 - laravel
 - lunem
 - artisan
---
Artisan 是 Laravel 自带的命令行接口，它提供了许多实用的命令来帮助你构建 Laravel 应用。要查看所有可用的 Artisan 命令的列表，可以使用 list 命令
`php artisan list`
<!--more-->
* Laravel 的 artisan 可用命令：
```
php artisan list
Laravel Framework 5.5.42

Usage:
  command [options] [arguments]

Options:
  -h, --help            Display this help message
  -q, --quiet           Do not output any message
  -V, --version         Display this application version
      --ansi            Force ANSI output
      --no-ansi         Disable ANSI output
  -n, --no-interaction  Do not ask any interactive question
      --env[=ENV]       The environment the command should run under
  -v|vv|vvv, --verbose  Increase the verbosity of messages: 1 for normal output, 2 for more verbose output and 3 for debug

Available commands:
  clear-compiled                 Remove the compiled class file
  down                           Put the application into maintenance mode
  env                            Display the current framework environment
  help                           Displays help for a command
  inspire                        Display an inspiring quote
  list                           Lists commands
  migrate                        Run the database migrations
  optimize                       Optimize the framework for better performance (deprecated)
  preset                         Swap the front-end scaffolding for the application
  serve                          Serve the application on the PHP development server
  tinker                         Interact with your application
  up                             Bring the application out of maintenance mode
 app
  app:name                       Set the application namespace
 auth
  auth:clear-resets              Flush expired password reset tokens
 cache
  cache:clear                    Flush the application cache
  cache:forget                   Remove an item from the cache
  cache:table                    Create a migration for the cache database table
 config
  config:cache                   Create a cache file for faster configuration loading
  config:clear                   Remove the configuration cache file
 db
  db:seed                        Seed the database with records
 debugbar
  debugbar:clear                 Clear the Debugbar Storage
 event
  event:generate                 Generate the missing events and listeners based on registration
 ide-helper
  ide-helper:eloquent            Add \Eloquent helper to \Eloquent\Model
  ide-helper:generate            Generate a new IDE Helper file.
  ide-helper:meta                Generate metadata for PhpStorm
  ide-helper:models              Generate autocompletion for models
 key
  key:generate                   Set the application key
 make
  make:auth                      Scaffold basic login and registration views and routes
  make:command                   Create a new Artisan command
  make:controller                Create a new controller class
  make:event                     Create a new event class
  make:exception                 Create a new custom exception class
  make:factory                   Create a new model factory
  make:historyToday              create history today
  make:job                       Create a new job class
  make:listener                  Create a new event listener class
  make:mail                      Create a new email class
  make:middleware                Create a new middleware class
  make:migration                 Create a new migration file
  make:model                     Create a new Eloquent model class
  make:news                      CSDN latest 5 article
  make:notification              Create a new notification class
  make:policy                    Create a new policy class
  make:provider                  Create a new service provider class
  make:request                   Create a new form request class
  make:resource                  Create a new resource
  make:rule                      Create a new validation rule
  make:seeder                    Create a new seeder class
  make:test                      Create a new test class
 migrate
  migrate:fresh                  Drop all tables and re-run all migrations
  migrate:install                Create the migration repository
  migrate:refresh                Reset and re-run all migrations
  migrate:reset                  Rollback all database migrations
  migrate:rollback               Rollback the last database migration
  migrate:status                 Show the status of each migration
 migration
  migration:fromThinkPHPBjyBlog  Command description
 notifications
  notifications:table            Create a migration for the notifications table
 opcache
  opcache:clear                  Clear the opcode cache
  opcache:config                 Show your opcode cache configuration
  opcache:optimize               Pre-compile your application code
  opcache:status                 Show state information, memory usage, etc..
 package
  package:discover               Rebuild the cached package manifest
 queue
  queue:failed                   List all of the failed queue jobs
  queue:failed-table             Create a migration for the failed queue jobs database table
  queue:flush                    Flush all of the failed queue jobs
  queue:forget                   Delete a failed queue job
  queue:listen                   Listen to a given queue
  queue:restart                  Restart queue worker daemons after their current job
  queue:retry                    Retry a failed queue job
  queue:table                    Create a migration for the queue jobs database table
  queue:work                     Start processing jobs on the queue as a daemon
 route
  route:cache                    Create a route cache file for faster route registration
  route:clear                    Remove the route cache file
  route:list                     List all registered routes
 schedule
  schedule:run                   Run the scheduled commands
 seeder
  seeder:clear                   Clear seeder data
 session
  session:table                  Create a migration for the session database table
 storage
  storage:link                   Create a symbolic link from "public/storage" to "storage/app/public"

 vendor
  vendor:publish                 Publish any publishable assets from vendor packages
 view
  view:clear                     Clear all compiled view files
```


* 这是 Lumen 的 artisan 可用命令：
```
php artisan list
Laravel Framework Lumen (5.6.4) (Laravel Components 5.6.*)

Usage:
  command [options] [arguments]

Options:
  -h, --help            Display this help message
  -q, --quiet           Do not output any message
  -V, --version         Display this application version
      --ansi            Force ANSI output
      --no-ansi         Disable ANSI output
  -n, --no-interaction  Do not ask any interactive question
      --env[=ENV]       The environment the command should run under
  -v|vv|vvv, --verbose  Increase the verbosity of messages: 1 for normal output, 2 for more verbose output and 3 for debug

Available commands:
  help                Displays help for a command
  list                Lists commands
  migrate             Run the database migrations
 auth
  auth:clear-resets   Flush expired password reset tokens
 cache
  cache:clear         Flush the application cache
  cache:forget        Remove an item from the cache
  cache:table         Create a migration for the cache database table
 db
  db:seed             Seed the database with records
 make
  make:migration      Create a new migration file
  make:seeder         Create a new seeder class
 migrate
  migrate:fresh       Drop all tables and re-run all migrations
  migrate:install     Create the migration repository
  migrate:refresh     Reset and re-run all migrations
  migrate:reset       Rollback all database migrations
  migrate:rollback    Rollback the last database migration
  migrate:status      Show the status of each migration
 queue
  queue:failed        List all of the failed queue jobs
  queue:failed-table  Create a migration for the failed queue jobs database table
  queue:flush         Flush all of the failed queue jobs
  queue:forget        Delete a failed queue job
  queue:listen        Listen to a given queue
  queue:restart       Restart queue worker daemons after their current job
  queue:retry         Retry a failed queue job
  queue:table         Create a migration for the queue jobs database table
  queue:work          Start processing jobs on the queue as a daemon
 schedule
  schedule:run        Run the scheduled commands
```

Lumen 下的 Artisan 命令比 Laravel 的少很多。通过对比就知道
但是，有些命令没有也不影响原有功能的使用，毕竟 Artisan 命令工具只是起到辅助开发和提高效率的作用。
