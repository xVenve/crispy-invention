import { Pipe, PipeTransform } from '@angular/core';
import { Car } from './car';

@Pipe({
  name: 'filtroPorMarca',
})
export class FiltroPipe implements PipeTransform {
  transform(items: Car[], input: string): Car[] {
    if (input) {
      return items.filter((car) =>
        car.brand.toLocaleLowerCase().includes(input.toLocaleLowerCase())
      );
    } else {
      return items;
    }
  }
}
