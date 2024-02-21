import './ListaSuspensa.css'
import React from 'react'

interface ListaSuspensaProps {
    aoAlterado: (valor: string) => void
    label: string
    required?: boolean
    valor: string | number
    itens: string[]
}

const ListaSuspensa = ({ aoAlterado, label, required, valor, itens }: ListaSuspensaProps) => {
    return (
        <div className='lista-suspensa'>
            <label>{label}</label>
            <select onChange={evento => aoAlterado(evento.target.value)} required={required} value={valor}>
                <option value=""></option>
                {itens.map(item => {
                    return <option key={item}>{item}</option>
                })}
            </select>
        </div>
    )
}

export default ListaSuspensa