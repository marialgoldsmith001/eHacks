<?php
function query(/*$sql, $parameter*/){
    //SQL Statement
    $sql= func_get_arg(0);
    $parameters = array_slice(func_get_args(), 1);
    
    //try to connect to database
    static $handle;
    if(!isset($handle)){
        try{
            $dsn = 'mysql:dbname=mgutierrez_test; host=192.168.1.28';
            $user = 'root';
            $password = 'ig3tACCocESS2@Ll';
            //connec to database
            $handle = new PDO($dsn, $user, $password);
            $handle->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
        }
        catch(Exception $e){
            trigger_error($e->getMessage(), E_USER_ERROR);
            exit;
        }
        
    }
    //prepare SQL statement
    $statement = $handle->prepare($sql);
    if($statement === false){
        trigger_error($handle->errorInfo()[2], E_USER_ERROR);
        exit;
    }
    
    //execute SQL statement
    $results = $statement->execute($parameters);
    
    //return result rows if any
    if($results != false){
        return $statement->fetchAll(PDO::FETCH_ASSOC);
    }
    else{
        return false;
    }
}

function logout(){
    // unset any session variables
    $_SESSION = [];
    // expire cookie
    if (!empty($_COOKIE[session_name()]))
    {
        setcookie(session_name(), "", time() - 42000);
    }
    // destroy session
    session_destroy();
}


function redirect($destination){
    // handle URL
    if (preg_match("/^https?:\/\//", $destination))
    {
        header("Location: " . $destination);
    }
    // handle absolute path
    else if (preg_match("/^\//", $destination))
    {
        $protocol = (isset($_SERVER["HTTPS"])) ? "https" : "http";
        $host = $_SERVER["HTTP_HOST"];
        header("Location: $protocol://$host$destination");
    }
    // handle relative path
    else
    {
        // adapted from http://www.php.net/header
        $protocol = (isset($_SERVER["HTTPS"])) ? "https" : "http";
        $host = $_SERVER["HTTP_HOST"];
        $path = rtrim(dirname($_SERVER["PHP_SELF"]), "/\\");
        header("Location: $protocol://$host$path/$destination");
    }
    // exit immediately since we're redirecting anyway
    exit;
}
    


function render($template, $values = []){
    // if template exists, render it
    if (file_exists("../View/$template")){
        // extract variables into local scope
        extract($values);
        // render template
        require("../View/$template");
    }
    // else err
    else
    {
        trigger_error("Invalid template: $template", E_USER_ERROR);
    }
}