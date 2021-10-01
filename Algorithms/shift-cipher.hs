import Data.Char

splitString string = map (\el -> [el]) string
lowerLetters = splitString ['a'..'z']
upperLetters = splitString ['A'..'Z']

crypt message key = concatMap (\el -> let round = if isUpper el then 90 else 122 in [toEnum $ key + fromEnum el ::Char]) message

decrypt message key = crypt message $ negate key