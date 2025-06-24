<?php
class Book
{
    public $title;
    public $author;
}

$book1 = new Book();
$book1->title = "The Poor Dad Rich Dad";
$book1->author = "Robert Kiyosaki";
echo $book1->title . " by " . $book1->author;
?>