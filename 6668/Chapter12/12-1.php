<?php
$env = new Db4Env(); 
$env->open("myenv/", DB_CREATE|DB_INIT_LOCK|DB_INIT_LOG|DB_INIT_MPOOL|DB_INIT_TXN, 0); 
$mgr = new XmlManager($env, 0);  

