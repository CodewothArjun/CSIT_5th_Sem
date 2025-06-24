<?php
/* $cookie_name="Arjun";
    $cookie_value="John Doe";
    setcookie($cookie_name,$cookie_value,time()+(86400*30),"/");
    if(!isset($_COOKIE[$cookie_name])){
        echo $cookie_name." is not set";
    }else{
        echo $cookie_name." is set";
    }*/

// session_start();
// $_SESSION["username"]="John";
// $_SESSION["email"]="john@gmail.com";
// echo "session variables are set."

//Connection to the server through procedural process
// $servername="localhost";
// $username="root";
// $password="";

// //making connection
// $conn=mysqli_connect($servername,$username,$password);


// //checking the connection is built or not 
// if(!$conn){
//     die("Connection failed".mysqli_connect_error());
// }else{
//     echo "Connection is successful.";
// }

// server connection by object oriented
$servername = "localhost";
$username = "root";
$password = "";
$dbname="webTech";

$conn = new mysqli($servername, $username, $password,$dbname);

if (!$conn) {
    die("Connection Failed" . mysqli_connect_error());
} else {
    echo "Connection is successful..";
}

//Creating a database
// $sql="CREATE DATABASE webTech";
// if(mysqli_query($conn,$sql)){
//     echo "Database is created successfully";
// }else
//     echo "Database creating error".mysqli_error($conn);

//creating a table
// $sql = "CREATE TABLE Student (
// id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
// firstname VARCHAR(30) NOT NULL,
// lastname VARCHAR(30) NOT NULL,
// email VARCHAR(50)
// )";

// if (mysqli_query($conn, $sql)) {
//     echo "successfully created table 'student'";
// }

// inserting multiple data
$sql="INSERT INTO Student(id,firstname,lastname,email) VALUES('5','bibek','Rokka','bibek@gmail.com')";

if (mysqli_query($conn,$sql)) {
  echo "New record created successfully";
} 

