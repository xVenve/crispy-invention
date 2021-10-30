; Define la plantilla para la jarra
(deftemplate jarra
	(slot litros
		(type INTEGER)
		(default 0))
	(slot capacidad
		(type INTEGER))
)

; Inicializa la base de hechos
; (defrule estado-inicial
;  =>
;  (assert (jarra (capacidad 3)))
;  (assert (jarra (capacidad 4))))

(deffacts estado_inicial_jarras
	(jarra (capacidad 3))
	(jarra (capacidad 4))
)

; (defrule eliminar-duplicados
;     (declare (salience 100))
; 	?jarra1 <- (jarra (capacidad ?c) (litros ?l1))
; 	?jarra2 <- (jarra (capacidad ?c) (litros ?l2))
; 	(test (neq ?jarra1 ?jarra2))
; 	=>
; 	(retract ?jarra1)
; )

; Llena jarra
(defrule llena-jarra
	?jarra <- (jarra (capacidad ?c) (litros ?l))
	(test (< ?l ?c))
	=>
	(assert (jarra (capacidad ?c)(litros ?c)))
)

; Vacia jarra
(defrule vaciar-jarra
	?jarra <- (jarra (capacidad ?c) (litros ?l))
	(test (> ?l 0))
	=>
	(assert (jarra (capacidad ?c) (litros 0)))
)

; Vuelca el contenido de una jarra en la otra: jarra1 -> jarra2
(defrule volcar-jarra
	?jarra1 <- (jarra (litros ?l1)(capacidad ?c1))
	?jarra2 <- (jarra (litros ?l2) (capacidad ?c2))
	(test (neq ?jarra1 ?jarra2))
	(test (<> ?c1 ?c2))
	(test (<= (+ ?l1 ?l2) ?c2))
	=>
	(assert (jarra (capacidad ?c1)(litros 0)))
	(assert (jarra (capacidad ?c2)(litros (+ ?l1 ?l2))))
)

; Vuelca todo lo que quepa de una jarra en la otra: jarra1 -> jarra2
(defrule verter-jarra
	?jarra1 <- (jarra (litros ?l1)(capacidad ?c1))
	?jarra2 <- (jarra (litros ?l2) (capacidad ?c2))
	(test (neq ?jarra1 ?jarra2))
	(test (<> ?c1 ?c2))
	(test (> (+ ?l1 ?l2) ?c2))
	=>
	(assert (jarra (capacidad ?c1)(litros (- ?l1 (- ?c2 ?l2)))))
	(assert (jarra (capacidad ?c2)(litros ?c2)))
)

; Comprueba terminacion
(defrule acabar
	(declare (salience 1000))
	?jarra <- (jarra (capacidad 4) (litros 2))
	=>
	(printout t "Lo he conseguido" crlf)
	(halt)
)
