create table To_do (
    Id integer PRIMARY KEY NOT NULL,
    Titulo varchar(100) NOT NULL,
    Desenho integer  NOT NULL,
    Impressao integer NOT NULL,
    Completo integer NOT NULL
);

insert into To_do values(NULL, 'Maquete B', 2, 1, 0);
insert into To_do values(NULL, 'Modulo Eixo', 2, 2, 2);