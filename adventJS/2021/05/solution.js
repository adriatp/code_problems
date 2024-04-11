export default function daysToXmas(date) {
  let obj_date = new Date('Dec 25, 2021');
  var days = (obj_date-date)/86400000;
  return Math.ceil( days );
}
