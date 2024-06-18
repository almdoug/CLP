% Douglas Benevides Almeida

(defun A (m n)
  (cond ((= m 0) (+ n 1))
        ((= n 0) (A (- m 1) 1))
        (t (A (- m 1) (A m (- n 1))))))

;; Exemplo: A(2, 3)
(format t "A(2, 3) = ~d~%" (A 2 3))
