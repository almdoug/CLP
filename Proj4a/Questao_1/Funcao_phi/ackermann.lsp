%Douglas Benevides Almeida

(defun phi (m n p)
  (cond
    ((= p 0) (+ m n))
    ((= n 0) (cond
               ((= p 1) 0)
               ((= p 2) 1)
               (t m)))
    (t (phi m (phi m (- n 1) p) (- p 1)))))

;; Exemplo
(let ((m 2) (n 3) (p 2))
  (format t "phi(~d, ~d, ~d) = ~d~%" m n p (phi m n p)))
