<?php
    session_start();
    include 'connection.php';
    if(isset($_SESSION['email'])){
    echo '<script> window.location="homeUsuario.php"; </script>';
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <title>Uncle nostalgia</title>
    <link rel="stylesheet" href="css/styles-index.css">
</head>
<body>
    <header>
        <nav class="navbar navbar-inverse navbar-static-top" role="navigation">
            <div class="container">
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navegacion-fm">
                        <span class="sr-only">Desplegar / Ocultar Menú</span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>
                    <a href="index.php" class="navbar-brand">:')</a>
                </div>
                <!-- Inicia menú -->
                <div class="collapse navbar-collapse" id="navegacion-fm">
                    <ul class="nav navbar-nav">
                        <li><a href="#Login" data-toggle="modal"><span class="glyphicon glyphicon-log-in"></span> Login</a></li>
                        <li><a href="#SignUp" data-toggle="modal"><span class="glyphicon glyphicon-pencil"></span> Sign Up</a></li>
                    </ul>
                </div>
            </div>
        </nav>
    </header>
    <!-- Carousel -->
    <div id="myCarousel" class="carousel slide" data-ride="carousel">
        <ol class="carousel-indicators">
            <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
            <li data-target="#myCarousel" data-slide-to="1"></li>
            <li data-target="#myCarousel" data-slide-to="2"></li>
            <li data-target="#myCarousel" data-slide-to="3"></li>
        </ol>
        <div class="carousel-inner" role="listbox">
            <div class="item active">
                <img src="img/pvris_new.png" width="100%">
                <div class="carousel-caption">
                    <h3>PVRIS?</h3>
                </div>
            </div>
            <div class="item">
                <img src="img/paramore.png" width="100%">
                <div class="carousel-caption">
                    <h3>Paramore anuncia nuevo álbum.</h3>
                </div>

            </div>
            <div class="item">
                <img src="img/spo.png" width="100%">
                <div class="carousel-caption">
                    <h3>El mejor playlist para tu día.</h3>
                </div>
            </div>
            <div class="item">
                <img src="img/royal.png" width="100%">
                <div class="carousel-caption">
                    <h3>SPOILER!</h3>
                </div>
            </div>
        </div>
        <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
            <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
            <span class="sr-only">Previous</span>
        </a>
        <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
            <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
            <span class="sr-only">Next</span>
        </a>
    </div>
    <!-- Jumbotron -->
    <section class="jumbotron jumbotron-header">
        <script type="text/javascript">
            var FraseOp = new Array();
            FraseOp[0] = "Al Old MTV le gusta esto."
            FraseOp[1] = "EMO-cionante."
            FraseOp[2] = "¿2007?"
            FraseOp[3] = ":D:"
            FraseOp[4] = "Macho que se respeta..."
            FraseOp[5] = "Smells like 2007"
            var Q = FraseOp.length;
            var estaFraseVa = Math.round(Math.random()*(Q-1));
            document.write("<h3>" + FraseOp[estaFraseVa] + "</h3>");
        </script>
    </section>
    <!-- Lo + escuchado paps -->
    <div class="container">
        <div class="row">   
            <article class="main col-xs-12 col-sm-6 col-md-8">
                <h3>Comentario Principal</h3>
            </article>
            <aside class="main col-xs-12 col-sm-6 col-md-4">
                <h2 class="page-header text-center">Lo + escuchado paps:</h2>
                <div class="list-group">
                    <a href="#cancionSemanal1" class="btn btn-default btn-md btn-block" data-toggle="modal">Heaven - PVRIS</a>
                    <a href="#cancionSemanal2" class="btn btn-default btn-md btn-block" data-toggle="modal">Hard Times - Paramore</a>
                    <a href="#cancionSemanal3" class="btn btn-default btn-md btn-block" data-toggle="modal">Saturnz Barz - Gorillaz</a>

                    <div class="modal fade" id="cancionSemanal1">
                        <div class="modal-dialog">
                            <div class="modal-content">
                                <!-- header ventana -->
                                <div class="modal-header">
                                    <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                                    <h4 class="modal-title">Heaven - PVRIS</h4>
                                </div>
                                <!-- Contenido ventana -->
                                <div class="modal-body">
                                    <div class="embed-responsive embed-responsive-16by9">
                                        <iframe src="https://embed.spotify.com/?uri=spotify%3Atrack%3A1WasQIPpSRf6osP8UgYfim" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="modal fade" id="cancionSemanal2">
                        <div class="modal-dialog">
                            <div class="modal-content">
                                <!-- header ventana -->
                                <div class="modal-header">
                                    <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                                    <h4 class="modal-title">Hard Times - Paramore</h4>
                                </div>
                                <!-- Contenido ventana -->
                                <div class="modal-body">
                                    <div class="embed-responsive embed-responsive-16by9">
                                        <iframe src="https://embed.spotify.com/?uri=spotify%3Atrack%3A5hHudNsfZXmdgefWxAX2LG" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="modal fade" id="cancionSemanal3">
                        <div class="modal-dialog">
                            <div class="modal-content">
                                <!-- header ventana -->
                                <div class="modal-header">
                                    <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                                    <h4 class="modal-title">Saturnz Barz - Gorillaz</h4>
                                </div>
                                <!-- Contenido ventana -->
                                <div class="modal-body">
                                    <div class="embed-responsive embed-responsive-16by9">
                                        <iframe src="https://embed.spotify.com/?uri=spotify%3Atrack%3A2oJInAFXiQYLgz0jh9MrXf" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>                
                </div>
            </aside>
        </div>
    </div>
    <br>
    <!-- Discos -->
    <div class="container">
        <div class="row">
            <div class="disco1 col-sm-12 col-md-4">
                <h4 class="disco">PVRIS - White Noise</h4>
                <a href="#D1" data-toggle="modal"><img src="img/wht.jpg" width="100%"></a>
            </div>
            <div class="disco2 col-sm-12 col-md-4">
                <h4 class="disco">Bring me the Horizon - Sempiternal</h4>
                <a href="#D2" data-toggle="modal"><img src="img/smpt.jpg" width="100%"></a>
            </div>
            <div class="disco3 col-sm-12 col-md-4">
                <h4 class="disco">Royal Blood - Royal Blood</h4>
                <a href="#D3" data-toggle="modal"><img src="img/blood.jpg" width="100%"></a>
            </div>
            <div class="modal fade" id="D1">
                <div class="modal-dialog modal-lg">
                    <div class="modal-content">
                        <!-- header ventana -->
                        <div class="modal-header">
                            <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                            <h4 class="modal-title">PVRIS - White Noise</h4>
                        </div>
                        <!-- Contenido ventana -->
                        <div class="modal-body">
                            <div class="embed-responsive embed-responsive-16by9">
                                <iframe src="https://embed.spotify.com/?uri=spotify%3Aalbum%3A7acEEWUWq2GVgeS9tr9cOp" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div class="modal fade" id="D2">
                <div class="modal-dialog modal-lg">
                    <div class="modal-content">
                        <!-- header ventana -->
                        <div class="modal-header">
                            <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                            <h4 class="modal-title">Bring me the Horizon - Sempiternal</h4>
                        </div>
                        <!-- Contenido ventana -->
                        <div class="modal-body">
                            <div class="embed-responsive embed-responsive-16by9">
                                <iframe src="https://embed.spotify.com/?uri=spotify%3Aalbum%3A4dhfdOEUI4tfqwdgouFTQA" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div class="modal fade" id="D3">
                <div class="modal-dialog modal-lg">
                    <div class="modal-content">
                        <!-- header ventana -->
                        <div class="modal-header">
                            <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                            <h4 class="modal-title">Royal Blood - Royal Blood</h4>
                        </div>
                        <!-- Contenido ventana -->
                        <div class="modal-body">
                            <div class="embed-responsive embed-responsive-16by9">
                                <iframe src="https://embed.spotify.com/?uri=spotify%3Aalbum%3A0BFzNaeaNv4mahOzwZFGHK" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <!-- Ventana Login -->
            <div class="modal fade" id="Login">
                <div class="modal-dialog">
                    <div class="modal-content">
                        <!-- header ventana -->
                        <div class="modal-header">
                            <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                            <h4 class="modal-title">Login</h4>
                        </div>
                        <!-- Contenido ventana -->
                        <div class="modal-body">
                            <div class="embed-responsive embed-responsive-16by9">
                                <form class="form-group" method="POST" action="login.php">
                                    <div class="form-group text-center">
                                        <label>Email</label>
                                        <input type="email" class="form-control" id="email" name="email">
                                    </div>
                                    <div class="form-group text-center">
                                        <label>Password</label>
                                        <input type="password" class="form-control" id="pass" name="pass">
                                    </div>
                                    <button type="submit" class="btn btn-primary btn-block" name="login">Log in</button>
                                </form>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <!-- Ventana Sign Up-->
            <div class="modal fade" id="SignUp">
                <!--<div class="modal-dialog" style="width: 640px;">-->
                <div class="modal-dialog modal-lg">
                    <div class="modal-content">
                        <!-- header ventana -->
                        <div class="modal-header">
                            <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                            <h4 class="modal-title">Sign Up</h4>
                        </div>
                        <!-- Contenido ventana -->
                        <div class="modal-body">
                            <div class="embed-responsive embed-responsive-16by9">
                                <form class="form-group" method="POST" action="signup.php">
                                    <div class="form-group text-center">
                                        <label>Nombre</label>
                                        <input type="text" class="form-control" id="nombre" name="nombre">
                                    </div>
                                    <div class="form-group text-center">
                                        <label>Apellido</label>
                                        <input type="text" class="form-control" id="apellido" name="apellido">
                                    </div>
                                    <div class="form-group text-center">
                                        <label>Nickname</label>
                                        <input type="text" class="form-control" id="nick" name="nick">
                                    </div>
                                    <div class="form-group text-center">
                                        <label>Email</label>
                                        <input type="email" class="form-control" id="email" name="email">
                                    </div>
                                    <div class="form-group text-center">
                                        <label>Password</label>
                                        <input type="password" class="form-control" id="pass" name="pass">
                                    </div>
                                    <button type="submit" class="btn btn-primary btn-block">Sign Up</button>
                                </form>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <br>
    <footer>
        <div class="container">
            <div class="col-xs-12">
                <h5 class="text-center">&#60;/white_noise&#62;</h5>
            </div>
        </div>
    </footer>
</body>
</html>