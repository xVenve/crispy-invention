(defclass ANIMAL (is-a USER)
    (slot nombre
        (type STRING)
        (default ?NONE))
    (slot piel
        (type SYMBOL)
        (allowed-symbols pelo plumas))
    (slot vuela
        (type SYMBOL)
        (allowed-symbols si no))
    (slot razona
        (type SYMBOL)
        (allowed-symbols si no)))

(defclass MAMIFERO (is-a ANIMAL)
    (slot piel
        (source composite)
        (default pelo)))
    
(defclass AVE (is-a ANIMAL)
    (slot piel
        (source composite)
        (default plumas)))
    
(defclass HOMBRE (is-a MAMIFERO)
    (slot nombre
        (source composite)
        (default ?NONE))
    (slot vuela
        (source composite)
        (default no))
    (slot razona
        (source composite)
        (default si)))

(defclass ALBATROS (is-a AVE)
    (slot vuela
        (source composite)
        (default si)))

(defclass PINGUINO (is-a AVE)
    (slot vuela
        (source composite)
        (default no)))

(definstances animales-iniciales
    (of HOMBRE (nombre Pepe))
    (of ALBATROS (nombre Alf))
    (of PINGUINO (nombre Chilly))
    (of PINGUINO (nombre Pingu)))

(defrule imprimir-pingu
    (object (is-a PINGUINO) (nombre ?pinguinos))
    =>
    (print "Pinguino "?pinguinos crlf))

(defrule imprimir-plumas
    (object (is-a AVE) (nombre ?plumas)(piel plumas))
    =>
    (print "Plumas "?plumas crlf))

(defrule imprimir-ave
    (object (is-a AVE) (nombre ?ave))
    =>
    (print "Ave " ?ave crlf))