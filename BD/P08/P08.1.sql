-- FICHA 8
-- 1
-- Crie a tabela AUTORES2, analoga a tabela AUTORES contendo as seguintes restricoes:
--  - Os nomes devem ser em maiusculas;
--  - A idade tem que ser um valor positivo menor 200.

CREATE TABLE AUTORES2 (
  CODIGO_AUTOR NUMBER(4, 0),
  NOME VARCHAR2(30) NOT NULL,
  N_CONTRIBUINTE NUMBER(9, 0) NOT NULL,
  MORADA VARCHAR2(50),
  IDADE NUMBER(4, 0),
  SEXO CHAR(1),
  NACIONALIDADE VARCHAR2(20),
  GENERO_PREFERIDO VARCHAR2(20),

  CONSTRAINT PK_ID_AUTOR2_pk PRIMARY KEY (CODIGO_AUTOR),
  CONSTRAINT PK_ID_AUTOR2_uk UNIQUE (N_CONTRIBUINTE),
  CONSTRAINT NOME_UPPER_check CHECK (NOME = upper(NOME)),
  CONSTRAINT IDADE_MAX_check CHECK (IDADE BETWEEN 0 AND 200));
