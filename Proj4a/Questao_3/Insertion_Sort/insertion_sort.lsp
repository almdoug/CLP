%Douglas Benevides Almeida

(defun inserir (x lista)
  (cond ((null lista) (list x))
        ((<= x (car lista)) (cons x lista))
        (t (cons (car lista) (inserir x (cdr lista))))))

(defun insertion-sort (lista)
  (if (null lista)
      nil
      (inserir (car lista) (insertion-sort (cdr lista)))))

;; Exemplo
(let ((lista (list 5 3 8 1 4)))
  (format t "Lista original: ~a~%" lista)
  (format t "Lista ordenada: ~a~%" (insertion-sort lista)))