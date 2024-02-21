import './CampoTexto.css'

import React from 'react'

interface CampoTextoProps {
    placeholder: string
    aoAlterado: (valor: string) => void
    label: string
    valor: string
    obrigatorio?: boolean
    tipo?: 'text' | 'password' | 'date' | 'email' | 'number'
}

const CampoTexto = ({ placeholder, aoAlterado, label, valor, obrigatorio = false, tipo = 'text' }: CampoTextoProps) => {

    const placeholderModificada = `${placeholder}...` 

    const aoDigitado = (evento: any) => {
        aoAlterado(evento.target.value)
    }

    return (
        <div className="campo-texto">
            <label>
                {label}
            </label>
            <input 
                value={valor} 
                onChange={aoDigitado} 
                type={tipo}
                required={obrigatorio} 
                placeholder={placeholderModificada}
            />
        </div>
    )
}

export default CampoTexto