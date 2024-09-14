const request = require('supertest');
const app = require('../src/app');

describe('GET /', () => {
  it('should return Hello, World!', async () => {
    const res = await request(app).get('/');
    expect(res.statusCode).toEqual(200);
    expect(res.text).toBe('Hello, World!');
  });
});

afterAll(done => {
  // Cierra cualquier operación asíncrona o servidor que pueda estar activo
  done();
});
